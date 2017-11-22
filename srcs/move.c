/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:15 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/22 11:37:29 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			mouserotate(t_fdfenv *env)
{
		env->rotate.z -=
			((float)env->mouse.x - (float)env->width / 2) / env->width;
		env->rotate.x +=
			((float)env->mouse.y - (float)env->height / 2) / env->height;
}

void			zoom(t_fdfenv *env)
{
	env->zoom++;
}

void			dezoom(t_fdfenv *env)
{
	if (env->zoom > 1)
		env->zoom--;
}

void			left(t_fdfenv *env)
{
	env->camera.a.x -= 10;
}

void			up(t_fdfenv *env)
{
	env->camera.a.y -= 10;
}

void			down(t_fdfenv *env)
{
	env->camera.a.y += 10;
}

void			right(t_fdfenv *env)
{
	env->camera.a.x += 10;
}
