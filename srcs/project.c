#include "fdf.h"


void		project(t_fdfenv *env, t_point point, t_pixel *pixel)
{
	pixel->x = env->camera.a.z * (point.x - (env->camera.a.x));
	pixel->y = env->camera.a.z * (point.y - (env->camera.a.y));
//ft_printf("%d %d\n",pixel->x,pixel->y);
	if (env->camera.a.z + point.z)
	{
		pixel->x /= env->camera.a.z + point.z;
		pixel->y /= env->camera.a.z + point.z;
	}
	pixel->x *=  env->zoom;
	pixel->y *=  env->zoom;
	pixel->x += env->width / 2;
	pixel->y += env->height / 2;
}

