/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:34:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/22 09:44:43 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			error(void)
{
	ft_printf("error\n");
	exit(0);
}

void			init_env(t_fdfenv *env)
{
	int	bpp;
	int	s_l;
	int	endian;

	env->mlx = mlx_init();
	env->width = 1200;
	env->height = 700;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "test");
	env->camera.a.x = -15;
	env->camera.a.y = -15;
	env->camera.a.z = 2000;
	env->zoom = 100 / env->mapsize.x + 1;
	env->top = 1;
	env->key = -1;
	env->pointsize = 1;
	env->rotate.x = -1.2;
	env->rotate.y = 0;
	env->rotate.z = -1.16;
	env->x = 1;
	env->y = 1;
}

void			getmap(t_fdfenv *env, char *path)
{
	int		fd;
	int		i;
	int		j;
	char	**strmap;
	char	**strmap2;

	i = 0;
	strmap = (char **)malloc(sizeof(char*));
	if ((fd = open(path, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &(strmap[i])) > 0)
		{
			i++;
			strmap2 = (char **)malloc(i * sizeof(char*));
			j = 0;
			while (j < i)
			{
				strmap2[j] = strmap[j];
				j++;
			}
			strmap = (char **)malloc((i + 1) * sizeof(char*));
			j = 0;
			while (j < i)
			{
				strmap[j] = strmap2[j];
				j++;
			}
			strmap[j] = NULL;
		}
		mapparse(env, strmap);
		close(fd);
	}
	else
		error();
	if (env->mapsize.y == 0)
		error();
}

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	size_t		i;
	t_fdfenv	env;

	i = 0;
	if (ac == 1)
		error();
	getmap(&env, av[1]);
	init_env(&env);
	drawpoint(&env);
	mlx_key_hook(env.win, keypressed, &env);
	mlx_mouse_hook(env.win, buttonpressed, &env);
	mlx_loop_hook(env.mlx, loopachieved, &env);
	mlx_loop(env.mlx);
	return (0);
}
