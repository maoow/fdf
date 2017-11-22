/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movepoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:06:41 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/22 10:19:04 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			higherpoint(t_fdfenv *env)
{
	env->map[env->x][env->y].z++;
}

void			lowerpoint(t_fdfenv *env)
{
	env->map[env->x][env->y].z--;
}

void			higher(t_fdfenv *env)
{
	env->top++;
}

void			lower(t_fdfenv *env)
{
	env->top--;
}

void			selectpoint(t_fdfenv *env)
{
	t_pixel tmp;
	t_pixel diff;
	int		i;
	int		j;

	i = 0;
	while (i < env->mapsize.y)
	{
		j = 0;
		while (j < env->mapsize.x)
		{
			project(env, env->map[i][j], &tmp);
			diff.x = env->mouse.x - tmp.x;
			diff.y = env->mouse.y - tmp.y;
			if (diff.x < env->pointsize && diff.x > -env->pointsize &&
					diff.y < env->pointsize && diff.y > -env->pointsize)
			{
				env->x = i;
				env->y = j;
			}
			j++;
		}
		i++;
	}
}

void			dpointsize(t_fdfenv *env)
{
	if (env->pointsize >= 1)
		env->pointsize--;
}

void			ipointsize(t_fdfenv *env)
{
	env->pointsize++;
}
