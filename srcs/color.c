/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:13:37 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:48:17 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background(t_fdfenv *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->width)
	{
		j = 0;
		while (j < env->height)
		{
			pixel_add(env, i, j, env->color);
			j++;
		}
		i++;
	}
}

void	icolor(t_fdfenv *env)
{
	if (env->y >= 0 && env->y < env->mapsize.y && env->x >= 0
			&& env->x < env->mapsize.x)
	{
		if (env->map[env->x][env->y].color <= 0x100000)
			env->map[env->x][env->y].color += 0x20;
		else
			env->map[env->x][env->y].color = 0xff0000;
	}
}

void	dcolor(t_fdfenv *env)
{
	if (env->y >= 0 && env->y < env->mapsize.y && env->x >= 0
			&& env->x < env->mapsize.x)
	{
		if (env->map[env->x][env->y].color >= 0x10)
			env->map[env->x][env->y].color -= 0x20;
		else
			env->map[env->x][env->y].color = 0x10;
	}
}

void	ibgcolor(t_fdfenv *env)
{
	env->color *= 0x2;
	if (env->color > 0x100000)
		env->color = 0xff0000;
}

void	dbgcolor(t_fdfenv *env)
{
	env->color /= 0x2;
	if (env->color < 0x10)
		env->color = 0x10;
}
