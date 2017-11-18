/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:34:54 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/17 13:28:48 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#define K_NB 15
#define B_NB 5


typedef struct	s_fpoint
{
	float	x;
	float	y;
	float	z;
}		t_fpoint;
typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct	s_vertex
{
	t_point	a;
	t_point	b;
}		t_vertex;

typedef struct	s_pixel
{
	int	x;
	int	y;
}		t_pixel;

typedef struct	s_line
{
	t_pixel	a;
	t_pixel	b;
}		t_line;
typedef struct	s_fdfenv
{
	void		*mlx;
	void		*win;
	size_t		width;
	size_t		height;
	size_t		x;
	size_t		y;
	size_t		top;
	size_t		zoom;
	t_vertex	camera;
	t_point		**map;
	t_point		mapsize;
	t_fpoint	rotate;
	void		*img;
	unsigned int	*imgstr;
	int		key;
	t_pixel		mouse;
}	t_fdfenv;

int			keypressed(int key, t_fdfenv *env);
int			buttonpressed(int key,int x, int y, t_fdfenv *env);
int			loopachieved(t_fdfenv *env);
void			right(t_fdfenv *env);
void			down(t_fdfenv *env);
void			up(t_fdfenv *env);
void			left(t_fdfenv *env);
void			center(t_fdfenv *env);
void			lower(t_fdfenv *env);
void			higher(t_fdfenv *env);
void			zoom(t_fdfenv *env);
void			dezoom(t_fdfenv *env);
void			maprotate(t_fdfenv *env);
void			mouserotate(t_fdfenv *env);
void		drawpoint(t_fdfenv *env);
void		project(t_fdfenv *env, t_point point, t_pixel *pixel);
void		drawline(t_fdfenv *env, t_pixel a, t_pixel b);
