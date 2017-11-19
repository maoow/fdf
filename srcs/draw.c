#include "fdf.h"

void		point_add(t_fdfenv *env, int x, int y, int color)
{
	int i;
	int j;
	env->pointsize = env->smooth - 1;
	j = -env->pointsize;
	while (j <= env->pointsize)
	{
		i = -env->pointsize;
		while (i <= env->pointsize)
		{
			if (x + i < env->width && x + i >= 0 && y + j < env->height && y + j >= 0)
			{
				if (
						env->pointsize < 2 ||
						!(
							(i == env->pointsize || i == -env->pointsize)
							&& (j == env->pointsize || j == -env->pointsize)
						 )
				   )
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
	while (pen.x * dir.x <= pb.x * dir.x)
	{
		pen.y = a * pen.x + b;
		pixel_add(env, pen.x, pen.y,  (0x888888 & (pa.color | pb.color)) | (pa.color & pb.color));
		while ((dir.y * pen.y <= (a * (pen.x + dir.x) + b) * dir.y )  && (dir.y * pen.y <= pb.y * dir.y))
		{
			pen.y += dir.y;
			pixel_add(env, pen.x, pen.y,  (0x888888 & (pa.color | pb.color))  | (pa.color & pb.color));
		}
		pen.x += dir.x;
	}
	point_add(env, pa.x, pa.y, pb.color);
}
void		ddrawline(t_fdfenv *env, t_pixel a, t_pixel b)
{
	t_pixel	pen;
	t_pixel	target;
	t_pixel	dir;
	t_pixel	mod;
	size_t	i;

	i = 0;
	pen.x = 0;
	pen.y = 0;
	dir.x = 1;
	dir.y = 1;
	mod.x = env->smooth;
	mod.y = env->smooth;
	target.x = b.x - a.x;
	target.y = b.y - a.y;
	if (target.x < 0)
		dir.x = -1;
	if (target.y < 0)
		dir.y = -1;
	if (abs(target.x) > abs(target.y) && abs(target.y))
	{
		mod.y = round((abs(target.x) * env->smooth) / abs(target.y));
	}
	else if (abs(target.x))
		mod.x = round((abs(target.y) * env->smooth) / abs(target.x));
	if (mod.x == 0)
	{
		mod.x = env->smooth;
		mod.y += env->smooth;
	}
	if (mod.y == 0)
	{
		mod.y = env->smooth;
		mod.x += env->smooth;
	}
	while (target.x != pen.x || target.y != pen.y)
	{
		if (i % mod.x == 0 && pen.x != target.x)
			pen.x += dir.x;
		if (i % mod.y == 0 && pen.y != target.y)
			pen.y += dir.y;
		i++;
		pixel_add(env, a.x + pen.x, a.y + pen.y,  (a.color | b.color) );
	}
}

void		drawpoint(t_fdfenv *env)
{
	int	i;
	int	j;
	t_pixel	tmp;
	t_pixel	tmp2;
	int	bpp;
	int	s_l;
	int	endian;
	i = 0;
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->imgstr= (unsigned int *)mlx_get_data_addr(env->img,&(bpp), &(s_l), &(endian));
	while (i < env->mapsize.y)
	{
		j = 0;
		while (j < env->mapsize.x)
		{
			project(env, env->map[i][j], &tmp);
			if (i < env->mapsize.y - 1)
			{
				project(env, env->map[i + 1][j], &tmp2);
				drawline(env, tmp,tmp2);
			}
			j++;
			if (j < env->mapsize.x)
			{
				project(env, env->map[i][j], &tmp2);
				drawline(env, tmp,tmp2);
			}
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx,env->win,env->img,0,0);
	mlx_destroy_image(env->mlx, env->img);
}
