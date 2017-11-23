/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawaccessor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:43:28 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:47:20 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		point_add(t_fdfenv *env, int x, int y, int color)
{
	int i;
	int j;

	j = -env->pointsize;
	while (j < env->pointsize)
	{
		i = -env->pointsize;
		while (i < env->pointsize)
		{
			if (x + i < env->width && x + i >= 0 &&
					y + j < env->height && y + j >= 0)
			{
				if (env->pointsize < 2 ||
						!((i == env->pointsize || i == -env->pointsize)
							&& (j == env->pointsize || j == -env->pointsize)))
					env->imgstr[x + i + (y + j) * env->width] = color;
			}
			i++;
		}
		j++;
	}
}

void		pixel_add(t_fdfenv *env, int x, int y, int color)
{
	if (x < env->width && x >= 0 && y < env->height && y >= 0)
	{
		env->imgstr[x + y * env->width] = color;
	}
}
