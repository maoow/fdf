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
	env->camera.a.x = -10;
	env->camera.a.y = -10;
	env->camera.a.z = 5;
	env->camera.b.x = 10;
	env->camera.b.y = 10;
	env->camera.b.z = 0;
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
	if ((fd = open(path, O_RDONLY)))
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
	}
	mapparse(env, strmap);
}

int			main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	size_t	i;
	t_fdfenv env;

	i = 0 ;
	init_env(&env);
	getmap(&env, av[1]);
drawpoint(&env);
	mlx_key_hook(env.win, keypressed, &env);
	mlx_mouse_hook(env.win, buttonpressed, &env);
	mlx_loop(env.mlx);
	return (0);
}
