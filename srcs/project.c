#include "fdf.h"


void		project(t_fdfenv *env, t_point point, t_pixel *pixel)
{
	pixel->x = env->camera.a.x * (point.x - (env->camera.a.x));
	pixel->y = env->camera.a.y * (point.y - (env->camera.a.y));
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
			ft_printf("%d %d\n",tmp.x, tmp.y);
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
