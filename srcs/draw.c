#include "fdf.h"

void		pixel_add(t_fdfenv *env, int x, int y, int color)
{
	if (x < env->width && x >= 0 && y < env->height && y >= 0)
{
	env->imgstr[x + y * env->width] = color;
}
}
void		drawline(t_fdfenv *env, t_pixel a, t_pixel b)
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
	mod.x = 1;
	mod.y = 1;
	target.x = b.x - a.x;
	target.y = b.y - a.y;
	if (target.x < 0)
		dir.x = -1;
	if (target.y < 0)
		dir.y = -1;
	if (abs(target.x) > abs(target.y) && abs(target.y))
		mod.y = abs(target.x) / abs(target.y);
	else if (abs(target.x))
		mod.x = abs(target.y) / abs(target.x);
if (mod.x == 0)
		mod.x = 1;
if (mod.y == 0)
		mod.y = 1;
	while (target.x != pen.x || target.y != pen.y)
	{
		if (i % mod.x == 0 && pen.x != target.x)
			pen.x += dir.x;
		if (i % mod.y == 0 && pen.y != target.y)
			pen.y += dir.y;
		i++;
		pixel_add(env, a.x + pen.x, a.y + pen.y, 0x00FFFFFF);
	}
}

void		drawpoint(t_fdfenv *env)
{
ft_printf("%d\n", env->camera.a.z);
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
