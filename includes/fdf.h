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
#define K_NB 5


typedef struct	s_point
{
	size_t	x;
	size_t	y;
	size_t	z;
}		t_point;

typedef struct	s_vertex
{
	t_point	a;
	t_point	b;
}		t_vertex;

typedef struct	s_pixel
{
	size_t	x;
	size_t	y;
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
	t_vertex	camera;
	t_point		**map;
	t_point		mapsize;
	void		*img;
	unsigned int	*imgstr;
}	t_fdfenv;

int			keypressed(int key, t_fdfenv *env);
int			buttonpressed(int key,int x, int y, t_fdfenv *env);
void			right(t_fdfenv *env);
void			down(t_fdfenv *env);
void			up(t_fdfenv *env);
void			left(t_fdfenv *env);
