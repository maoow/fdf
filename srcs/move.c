#include "fdf.h"

void			left(t_fdfenv *env)
{
env->camera.a.z++;
drawpoint(env);
}
void			up(t_fdfenv *env)
{
	int	i;
	int	j;
	i = 0;
	while (i < env->mapsize.y)
	{
		j = 0;
		while (j < env->mapsize.x)
		{
			env->map[i][j].z++;
			j++;
		}
		i++;
	}
drawpoint(env);
}
void			down(t_fdfenv *env)
{
	int	i;
	int	j;
	i = 0;
	while (i < env->mapsize.y)
	{
		j = 0;
		while (j < env->mapsize.x)
		{
			env->map[i][j].z++;
			j++;
		}
		i++;
	}
drawpoint(env);
}
void			right(t_fdfenv *env)
{
env->camera.a.z--;
drawpoint(env);
}
