/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:31 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/22 09:27:21 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	getxrotatetype(t_fdfenv *env)
{
	if (env->key == k_u)
		return (0.2);
	if (env->key == k_i)
		return (-0.2);
	return (0);
}

float	getyrotatetype(t_fdfenv *env)
{
	if (env->key == k_7)
		return (0.2);
	if (env->key == k_8)
		return (-0.2);
	return (0);
}

float	getzrotatetype(t_fdfenv *env)
{
	if (env->key == k_o)
		return (0.2);
	if (env->key == k_y)
		return (-0.2);
	return (0);
}

void	rotate(t_point *point, t_fpoint r)
{
	int	x;
	int	y;
	int	z;

	x = point->x * cosf(r.z) - point->y * sinf(r.z);
	point->y = point->x * sinf(r.z) + point->y * cosf(r.z);
	point->x = x * cosf(r.y) - point->z * sinf(r.y);
	point->z = x * sinf(r.y) + point->z * cosf(r.y);

	z = point->z * cosf(r.x) - point->y * sinf(r.x);
	point->y = point->z * sinf(r.x) + point->y * cosf(r.x);
	point->z = z;
}

void	maprotate(t_fdfenv *env)
{
	int	i;
	int	j;

	env->rotate.z += getzrotatetype(env);
	env->rotate.x += getxrotatetype(env);
	env->rotate.y += getyrotatetype(env);
	drawpoint(env);
}
