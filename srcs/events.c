/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:09 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:23:14 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		quit(t_fdfenv *env)
{
	(void)env;
	exit(0);
}

int			g_button[B_NB] =
{
	2,
	4,
	5,
	1
};
void		(*g_buttonf[B_NB])() =
{
	&mouserotate,
	&zoom,
	&dezoom,
	&selectpoint
};

int			g_key[K_NB] =
{
	K_Q,
	K_ESC,
	K_H,
	K_J,
	K_K,
	K_L,
	K_F,
	K_D,
	K_M,
	K_COMMA,
	K_Y,
	K_U,
	K_I,
	K_O,
	K_7,
	K_8,
	K_A,
	K_S,
	K_E,
	K_R,
	K_C,
	K_V,
	K_X,
	K_Z,
	K_SPACE,
	K_POINT,
	K_SLASH
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
	&ipointsize,
	&ispeed,
	&dspeed,
	&icolor,
	&dcolor,
	&center,
	&ibgcolor,
	&dbgcolor
};

int			loopachieved(t_fdfenv *env)
{
	if (env->key == -1)
	{
		env->rotate.z += env->speed / env->zoom;
		drawmap(env);
	}
	return (0);
}

int			buttonpressed(int key, int x, int y, t_fdfenv *env)
{
	size_t		count;

	count = 0;
	env->mouse.x = x;
	env->mouse.y = y;
	env->key = key;
	while (count < B_NB && key != g_button[count])
		count++;
	if (count < B_NB)
		g_buttonf[count](env);
	else
		ft_printf("%d\n", key);
	drawmap(env);
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
	{
		ft_printf("%d\n", key);
		env->key = -1;
	}
	drawmap(env);
	return (0);
}
