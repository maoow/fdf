/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:09 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/22 10:15:15 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		quit(t_fdfenv *env)
{
	exit(0);
}

int			g_button[B_NB] =
{
	3,
	4,
	5,
	1,
	108
};
void		(*g_buttonf[B_NB])() =
{
	&mouserotate,
	&zoom,
	&dezoom,
	&selectpoint,
	&right
};

int			g_key[K_NB] =
{
	k_q,
	k_esc,
	k_h,
	k_j,
	k_k,
	k_l,
	k_f,
	k_d,
	k_m,
	k_comma,
	k_y,
	k_u,
	k_i,
	k_o,
	k_7,
	k_8,
	k_a,
	k_s,
	k_e,
	k_r
};
void		(*g_keyf[K_NB])() =
{
	&quit,
	&quit,
	&left,
	&down,
	&up,
	&right,
	&higher,
	&lower,
	&zoom,
	&dezoom,
	&maprotate,
	&maprotate,
	&maprotate,
	&maprotate,
	&maprotate,
	&maprotate,
	&higherpoint,
	&lowerpoint,
	&dpointsize,
	&ipointsize
};

int			loopachieved(t_fdfenv *env)
{
	if (env->key == -1)
	{
		env->rotate.z += 0.02 / env->zoom;
		drawpoint(env);
	}
}

int			buttonpressed(int key, int x, int y, t_fdfenv *env)
{
	size_t		count;

	count = 0;
	env->mouse.x = x;
	env->mouse.y = y;
	env->key = key;
	while (count < B_NB)
	{
		if (key == g_button[count])
			g_buttonf[count](env);
		count++;
	}
	drawpoint(env);
	return (0);
}

int			keypressed(int key, t_fdfenv *env)
{
	size_t		count;

	count = 0;
	env->key = key;
	while (count < K_NB && key != g_key[count])
		count++;
	if (count < K_NB)
		g_keyf[count](env);
	else
		env->key = -1;
	ft_printf("%d\n", key);
	drawpoint(env);
}
