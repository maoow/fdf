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
#include "mlx_int.h"

void	error()
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
	//env->img = mlx_new_image(env->mlx, env->width, env->height);
	//env->imgstr= (unsigned int *)mlx_get_data_addr(env->img,&(bpp), &(s_l), &(endian));
	//mlx_put_image_to_window(env->mlx,env->win,env->img,0,0);
	env->camera.a.x = -15;
	env->camera.a.y = -15;
	env->camera.a.z = 2000;
	env->zoom = 100 / env->mapsize.x + 1;
	env->top = 6;
	env->key = 0;
	env->smooth = 1;
	env->camera.b.x = 10;
	env->camera.b.y = 10;
	env->camera.b.z = 0;
	env->rotate.x = -1.2;
	env->rotate.y = 0;
	env->rotate.z = -1.16;
}
void			getmap(t_fdfenv *env, char *path)
{
	int fd;
	int	i;
	int	j;
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
	}
	else
		error();
	if (env->mapsize.y == 0)
		error();
}

int			main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	size_t	i;
	t_fdfenv env;

	i = 0 ;
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
