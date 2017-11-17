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

void			init_env(t_fdfenv *env)
{
int	bpp;
int	s_l;
int	endian;
	env->mlx = mlx_init();
	env->width = 500;
	env->height = 500;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "test");
	env->x = 20;
	env->y = 20;
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->imgstr= (unsigned int *)mlx_get_data_addr(env->img,&(bpp), &(s_l), &(endian));
	mlx_put_image_to_window(env->mlx,env->win,env->img,0,0);
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
	mlx_mouse_hook(env.win, buttonpressed, &env);
	mlx_loop(env.mlx);
	return (0);
}
