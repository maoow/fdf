/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:01 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/22 10:10:39 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		point_add(t_fdfenv *env, int x, int y, int color)
{
	int i;
	int j;

	j = -env->pointsize;
	while (j < env->pointsize)
	{
		i = -env->pointsize;
		while (i < env->pointsize)
		{
			if (x + i < env->width && x + i >= 0 &&
					y + j < env->height && y + j >= 0)
			{
				if (env->pointsize < 2 ||
						!((i == env->pointsize || i == -env->pointsize)
							&& (j == env->pointsize || j == -env->pointsize)))
					env->imgstr[x + i + (y + j) * env->width] = color;
			}
			i++;
		}
		j++;
	}
}

void		pixel_add(t_fdfenv *env, int x, int y, int color)
{
	if (x < env->width && x >= 0 && y < env->height && y >= 0)
	{
		env->imgstr[x + y * env->width] = color;
	}
}

void		drawline(t_fdfenv *env, t_pixel pa, t_pixel pb)
{
	t_pixel	pen;
	double	a;
	double	b;
	t_pixel	dir;

	dir.x = -1;
	if (pb.x - pa.x > 0)
		dir.x = 1;
	dir.y = -1;
	if (pb.y - pa.y > 0)
		dir.y = 1;
	a = (double)(pb.y - pa.y) / (pb.x - pa.x);
	b = pa.y - a * pa.x;
	pen.x = pa.x;
	pen.y = pa.y;
	while (pen.x * dir.x < pb.x * dir.x)
	{
		pen.y = a * pen.x + b;
		pixel_add(env, pen.x, pen.y, (0x888888 & (pa.color | pb.color)) |
				(pa.color & pb.color));
		while ((dir.y * pen.y <= (a * (pen.x + dir.x) + b) * dir.y)
				&& (dir.y * pen.y <= pb.y * dir.y))
		{
			pixel_add(env, pen.x, pen.y,
					(0x888888 & (pa.color | pb.color)) | (pa.color & pb.color));
			pen.y += dir.y;
		}
		pen.x += dir.x;
	}
	while (pen.y * dir.y <= pb.y * dir.y)
	{
		pixel_add(env, pen.x, pen.y,
				(0x888888 & (pa.color | pb.color)) | (pa.color & pb.color));
		pen.y += dir.y;
	}
}

void		drawpoint(t_fdfenv *env)
{
	int		i;
	int		j;
	t_pixel	tmp;
	t_pixel	tmp2;

	i = 0;
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->imgstr = (unsigned int *)mlx_get_data_addr(env->img, &(env->bpp),
			&(env->s_l), &(env->endian));
	while (i < env->mapsize.y)
	{
		j = 0;
		while (j < env->mapsize.x)
		{
			project(env, env->map[i][j], &tmp);
			if (i < env->mapsize.y - 1)
			{
				project(env, env->map[i + 1][j], &tmp2);
				drawline(env, tmp, tmp2);
			}
			if (i == env->x && j == env->y)
				tmp.color = 0xFF0000;
			point_add(env, tmp.x, tmp.y, tmp.color);
			tmp.color = env->map[i][j].color;
			j++;
			if (j < env->mapsize.x)
			{
				project(env, env->map[i][j], &tmp2);
				drawline(env, tmp, tmp2);
			}
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
