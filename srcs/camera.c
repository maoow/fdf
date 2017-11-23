/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:41:06 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:42:13 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			higher(t_fdfenv *env)
{
	env->top++;
}

void			lower(t_fdfenv *env)
{
	env->top--;
}

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
