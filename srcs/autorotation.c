/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autorotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:13:04 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:13:05 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ispeed(t_fdfenv *env)
{
	if (env->speed < .2)
		env->speed += 0.01;
	env->key = -1;
}

void	dspeed(t_fdfenv *env)
{
	if (env->speed > -.2)
		env->speed -= 0.01;
	env->key = -1;
}
