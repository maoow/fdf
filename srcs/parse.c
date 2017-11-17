#include "fdf.h"

void	addpoint(t_fdfenv *env, size_t x, size_t y, size_t z)
{
	env->map[y][x].x = x;
	env->map[y][x].y = y;
	env->map[y][x].z = z;
}

void	initmap(t_fdfenv *env)
{
	size_t	i;

	env->map = (t_point **)malloc(env->mapsize.y * sizeof(t_point *));
	i = 0;
	while (i < env->mapsize.y)
	{
		env->map[i] = (t_point *)malloc(env->mapsize.x * sizeof(t_point));
		i++;
	}
}

void	mapsize(t_fdfenv *env, char **strmap)
{
	size_t	i;
	size_t	j;
	size_t	x;

	j = 0;
	while (strmap[j])
	{
		x = 0;
		i = 0;
		while (strmap[j][i])
		{
			if (strmap[j][i])
				x++;
			while (strmap[j][i] && (ft_isdigit(strmap[j][i]) || strmap[j][i] == '-'))
				i++;
			while (strmap[j][i] && (!ft_isdigit(strmap[j][i]) && strmap[j][i] != '-'))
				i++;
		}
		env->mapsize.x = x;
		j++;
	}
	env->mapsize.y = j ;
	initmap(env);
}
void	mapparse(t_fdfenv *env, char **strmap)
{
	size_t	i;
	size_t	j;
	size_t	x;

	j = 0;
	mapsize(env, strmap);
	while (strmap[j])
	{
		x = 0;
		i = 0;
		while (strmap[j][i])
		{
			while (strmap[j][i] && (!ft_isdigit(strmap[j][i]) && strmap[j][i] != '-'))
				i++;
			if (strmap[j][i])
			{
				addpoint(env, x, j, ft_atoi(&strmap[j][i]));
				x++;
			}
			while (strmap[j][i] && (ft_isdigit(strmap[j][i]) || strmap[j][i] == '-'))
				i++;
		}
		j++;
	}
}
