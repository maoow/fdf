#include "fdf.h"

void		project(t_fdfenv *env, t_point point, t_pixel *pixel)
{
	t_point	tmp;
	tmp.x = point.x;
	tmp.y = point.y;
	tmp.z = point.z * env->top;
	rotate(&tmp, env->rotate);
	pixel->x = env->camera.a.z * (tmp.x - (env->camera.a.x));
	pixel->y = env->camera.a.z * (tmp.y - (env->camera.a.y));
	if (env->camera.a.z - tmp.z)
	{
		pixel->x /= env->camera.a.z - tmp.z;
		pixel->y /= env->camera.a.z - tmp.z;
	}
	pixel->x *=  env->zoom;
	pixel->y *=  env->zoom;
	pixel->x /=  25;
	pixel->y /=  25;
	pixel->x += env->width / 2;
	pixel->y += env->height / 2;
}

