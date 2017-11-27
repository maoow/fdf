/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:15 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:40:48 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			center(t_fdfenv *env)
{
	env->rotate.x = 0;
	env->rotate.y = 0;
	env->rotate.z = 0;
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
