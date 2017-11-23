/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:34:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:14:51 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			error(char *str)
{
	ft_printf("error: %s\n", str);
	exit(0);
}

void			init_env(t_fdfenv *env)
{
	env->mlx = mlx_init();
	env->width = 2200;
	env->height = 1000;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "test");
	env->camera.a.x = -15;
	env->camera.a.y = -15;
	env->camera.a.z = 2000;
	if (env->mapsize.x > env->mapsize.y)
		env->zoom = 100 / env->mapsize.x + 1;
	else
		env->zoom = 100 / env->mapsize.y + 1;
	env->top = 1;
	env->key = -1;
	env->speed = 0.02;
	env->pointsize = 0;
	env->rotate.x = -1.2;
	env->rotate.y = 0;
	env->rotate.z = -1.16;
	env->x = -1;
	env->color = 0x001100;
	env->y = -1;
}

static void		addline(char ***strmap, int i)
{
	char	**strmap2;
	int		j;

	strmap2 = (char **)malloc(i * sizeof(char *));
	j = 0;
	while (j < i)
	{
		strmap2[j] = (*strmap)[j];
		j++;
	}
	free(*strmap);
	*strmap = (char **)malloc((i + 1) * sizeof(char *));
	j = 0;
	while (j < i)
	{
		(*strmap)[j] = strmap2[j];
		j++;
	}
	free(strmap2);
	(*strmap)[j] = NULL;
}

void			getmap(t_fdfenv *env, char *path)
{
	int		fd;
	int		i;
	char	**strmap;

	i = 0;
	strmap = (char **)malloc(sizeof(char*));
	if ((fd = open(path, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &(strmap[i])) > 0)
		{
			i++;
			addline(&strmap, i);
		}
		if (i == 0)
			error("file not supported");
		mapparse(env, strmap);
		close(fd);
	}
	else
		error("file not supported");
	while (--i)
		free(strmap[i]);
	free(strmap);
	if (env->mapsize.y == 0)
		error("empty map");
}

int				main(int ac, char **av)
{
	size_t		i;
	t_fdfenv	env;

	i = 0;
	if (ac == 1)
		error("not arg");
	getmap(&env, av[1]);
	init_env(&env);
	drawmap(&env);
	mlx_key_hook(env.win, keypressed, &env);
	mlx_mouse_hook(env.win, buttonpressed, &env);
	mlx_loop_hook(env.mlx, loopachieved, &env);
	mlx_loop(env.mlx);
	return (0);
}
