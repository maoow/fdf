/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:28 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/22 10:00:59 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		project(t_fdfenv *env, t_point point, t_pixel *pixel)
{
	t_point	tmp;

	tmp.x = point.x;
	tmp.y = point.y;
	tmp.z = point.z * env->top;
	rotate(&tmp, env->rotate);
	pixel->x = env->camera.a.z * (tmp.x - (env->camera.a.x));
	pixel->y = env->camera.a.z * (tmp.y - (env->camera.a.y));
	if (env->camera.a.z - tmp.z)
	{
		pixel->x /= env->camera.a.z - tmp.z;
		pixel->y /= env->camera.a.z - tmp.z;
	}
	pixel->x *= env->zoom;
	pixel->y *= env->zoom;
	pixel->x /= 5;
	pixel->y /= 5;
	pixel->x += env->width / 2;
	pixel->y += env->height / 2;
	pixel->color = point.color;
}
