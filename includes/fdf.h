/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:34:54 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/22 10:00:24 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "mlx.h"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#define K_NB 20
#define B_NB 5


#define k_q 12
#define k_esc 53
#define k_h 4
#define k_j 38
#define k_k 40
#define k_l 37
#define k_m 46
#define k_f 3
#define k_d 2
#define k_comma 43
#define k_y 16
#define k_u 32
#define k_i 34
#define k_o 31
#define k_7 28
#define k_8 26
#define k_a 0
#define k_s 1
#define k_e 14
#define k_r 15


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
	int	color;
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
	int	color;
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
	int		x;
	int		y;
	size_t		top;
	size_t		timer;
	size_t		zoom;
	int		pointsize;
	t_vertex	camera;
	t_point		**map;
	t_point		mapsize;
	t_fpoint	rotate;
	void		*img;
	unsigned int	*imgstr;
	int		key;
	size_t		smooth;
	t_pixel		mouse;
	

	int		bpp;
	int		s_l;
	int		endian;

}	t_fdfenv;

int			keypressed(int key, t_fdfenv *env);
int			buttonpressed(int key,int x, int y, t_fdfenv *env);
int			loopachieved(t_fdfenv *env);
void	error();
void			right(t_fdfenv *env);
void			down(t_fdfenv *env);
void			up(t_fdfenv *env);
void			left(t_fdfenv *env);
void			center(t_fdfenv *env);
void			selectpoint(t_fdfenv *env);
void			lowerpoint(t_fdfenv *env);
void			higherpoint(t_fdfenv *env);
void			lower(t_fdfenv *env);
void			higher(t_fdfenv *env);
void			zoom(t_fdfenv *env);
void			dezoom(t_fdfenv *env);
void			maprotate(t_fdfenv *env);
void			mouserotate(t_fdfenv *env);
void			ipointsize(t_fdfenv *env);
void			dpointsize(t_fdfenv *env);
void		drawpoint(t_fdfenv *env);
void		project(t_fdfenv *env, t_point point, t_pixel *pixel);
void	save(t_fdfenv *env);
void		drawline(t_fdfenv *env, t_pixel a, t_pixel b);
