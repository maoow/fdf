#include "fdf.h"
#include <math.h>

float	getxrotatetype(t_fdfenv *env)
{
	if (env->key == 117)
		return (0.2);
	if (env->key == 105)
		return (-0.2);
	return (0);
}

float	getyrotatetype(t_fdfenv *env)
{
	if (env->key == 55)
		return (0.2);
	if (env->key == 56)
		return (-0.2);
	return (0);
}

float	getzrotatetype(t_fdfenv *env)
{
	if (env->key == 121)
		return (0.2);
	if (env->key == 111)
		return (-0.2);
	return (0);
}

void	rotate(t_point *point, t_fpoint r)
{
	int	x;
	int	y;
	int	z;

			x = point->x * cosf(r.z) - point->y * sinf(r.z);
			point->y = point->x * sinf(r.z) + point->y * cosf(r.z);
			point->x = x * cosf(r.y) - point->z * sinf(r.y);
			point->z = x * sinf(r.y) + point->z * cosf(r.y);

			z = point->z * cosf(r.x) - point->y * sinf(r.x);
			point->y = point->z * sinf(r.x) + point->y * cosf(r.x);
			point->z = z;
}

void	maprotate(t_fdfenv *env)
{
	int	i;
	int	j;

	env->rotate.z += getzrotatetype(env);
	env->rotate.x += getxrotatetype(env);
	env->rotate.y += getyrotatetype(env);
	drawpoint(env);
}
