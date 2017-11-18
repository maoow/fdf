#include "fdf.h"

void			left(t_fdfenv *env)
{
	env->x--;
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
			env->map[i][j].z *= 2;
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
			env->map[i][j].z /= 2;
			j++;
		}
		i++;
	}
drawpoint(env);
}
void			right(t_fdfenv *env)
{
	env->x++;
}
