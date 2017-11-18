#include "fdf.h"


void		project(t_fdfenv *env, t_point point, t_pixel *pixel)
{
	pixel->x = -env->camera.a.x * (point.x - (env->camera.a.x));
	pixel->y = -env->camera.a.y * (point.y - (env->camera.a.y));
	pixel->x *= 1;
	pixel->y *= 1;
ft_printf("%d %d\n",pixel->x,pixel->y);
	if (env->camera.a.z + point.z)
	{
		pixel->x /= env->camera.a.z + point.z;
		pixel->y /= env->camera.a.z + point.z;
	}
}

void		drawpoint(t_fdfenv *env)
{
	int	i;
	int	j;
	t_pixel	tmp;
	t_pixel	tmp2;
	i = 0;
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
}
