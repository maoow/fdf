/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:22 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 16:02:20 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		addpoint(t_fdfenv *env, size_t x, size_t y, char *str)
{
	int		z;
	size_t	i;

	i = 0;
	z = ft_atoi(str);
	env->map[y][x].x = (x - env->mapsize.x / 2) * (2000 / env->mapsize.x);
	env->map[y][x].y = (y - env->mapsize.y / 2) * (2000 / env->mapsize.x);
	env->map[y][x].z = z * 2;
	while (ft_isdigit(str[i]) || str[i] == '-')
		i++;
	if (str[i] == ',')
	{
		getcolor(&env->map[y][x], str + i);
		while (str[i] && str[i] != ' ')
			i++;
	}
	else if (!str[i] || str[i] == ' ')
		env->map[y][x].color = (z * 0xffffff) / 200 + 0x00ff00;
	else
		error("format error");
	return (i);
}

void	initmap(t_fdfenv *env)
{
	int	i;

	if ((env->map = (t_point **)malloc(env->mapsize.y * sizeof(t_point *)))
			== NULL)
		error("malloc");
	i = 0;
	while (i < env->mapsize.y)
	{
		if ((env->map[i] = (t_point *)malloc(env->mapsize.x * sizeof(t_point)))
				== NULL)
			error("malloc");
		i++;
	}
}

void	mapsize(t_fdfenv *env, char **strmap)
{
	int		i;
	int		j;
	int		x;

	j = 0;
	while (strmap[j])
	{
		x = 0;
		i = 0;
		while (strmap[j][i])
		{
			if (strmap[j][i] && strmap[j][i] != ' ')
				x++;
			while (strmap[j][i] && strmap[j][i] != ' ')
				i++;
			while (strmap[j][i] && (!ft_isdigit(strmap[j][i])
						&& strmap[j][i] != '-'))
				i++;
		}
		if (j && env->mapsize.x != x)
			error("not a rectangular map");
		env->mapsize.x = x;
		j++;
	}
	env->mapsize.y = j;
}

void	mapparse(t_fdfenv *env, char **strmap)
{
	size_t	i;
	size_t	j;
	size_t	x;

	j = 0;
	mapsize(env, strmap);
	initmap(env);
	while (strmap[j])
	{
		x = 0;
		i = 0;
		while (strmap[j][i])
		{
			while (strmap[j][i] && (!ft_isdigit(strmap[j][i])
						&& strmap[j][i] != '-'))
				i++;
			if (strmap[j][i])
			{
				i += addpoint(env, x, j, &strmap[j][i]);
				x++;
			}
		}
		j++;
	}
}
