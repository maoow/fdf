/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:34:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/17 13:42:17 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int		g_key[K_NB] =
{
	113,
	104,
	106,
	107,
	108
};

void			quit()
{
	exit(0);
}

void		(*g_keyf[K_NB])() =
{
	&quit,
	&left,
	&down,
	&up,
	&right
};
int			keypressed(int key, t_fdfenv *env)
{
	size_t		count;

	count = 0;
	while(count < K_NB)
	{
		if (key == g_key[count])
			g_keyf[count](env);
		count++;
	}
		mlx_pixel_put(env->mlx, env->win, env->x, env->y, 0x0000FF00);
}

void			init_env(t_fdfenv *env)
{
	env->mlx = mlx_init();
	env->width = 500;
	env->height = 500;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "test");
	env->x = 20;
	env->y = 20;

}

int			main()
{
	void	*mlx;
	void	*win;
	size_t	i;
	t_fdfenv env;

	i = 0 ;
	init_env(&env);
	mlx_key_hook(env.win, keypressed, &env);
	mlx_loop(env.mlx);
	return (0);
}
