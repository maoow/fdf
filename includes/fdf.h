/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:34:54 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:48:12 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# define K_NB 26
# define B_NB 4


#define k_q 113
 #define k_esc 65307
 #define k_h 104
 #define k_j 106
 #define k_k 107
 #define k_l 108
 #define k_m 109
 #define k_f 102
 #define k_d 100
 #define k_comma 44
 #define k_y 121
 #define k_u 117
 #define k_i 105
 #define k_o 111
 #define k_7 55
 #define k_8 56
 #define k_a 97
 #define k_s 115
 #define k_e 101
 #define k_r 114
 #define k_c 99
 #define k_v 118
 #define k_z 122
 #define k_x 120
 #define k_point 46
 #define k_slash 47


# define K_Q			12
# define K_ESC			53
# define K_H			4
# define K_J			38
# define K_K			40
# define K_L			37
# define K_M			46
# define K_F			3
# define K_D			2
# define K_COMMA		43
# define K_Y			16
# define K_U			32
# define K_I			34
# define K_O			31
# define K_7			28
# define K_8			26
# define K_A			0
# define K_S			1
# define K_E			14
# define K_R			15
# define K_C			8
# define K_V			9
# define K_Z			6
# define K_X			7
# define K_POINT		44
# define K_SLASH		47

typedef struct	s_fpoint
{
	float	x;
	float	y;
	float	z;
}				t_fpoint;
typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_vertex
{
	t_point	a;
	t_point	b;
}				t_vertex;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	color;
}				t_pixel;

typedef struct	s_line
{
	t_pixel	a;
	t_pixel	b;
}				t_line;
typedef struct	s_fdfenv
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	double			speed;
	int				x;
	int				y;
	size_t			top;
	size_t			timer;
	size_t			zoom;
	int				pointsize;
	t_vertex		camera;
	t_point			**map;
	t_point			mapsize;
	t_fpoint		rotate;
	void			*img;
	unsigned int	*imgstr;
	int				key;
	size_t			smooth;
	t_pixel			mouse;
	int				color;
	int				bpp;
	int				s_l;
	int				endian;

}				t_fdfenv;

int				keypressed(int key, t_fdfenv *env);
int				buttonpressed(int key, int x, int y, t_fdfenv *env);
int				loopachieved(t_fdfenv *env);
void			error();
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
void			drawmap(t_fdfenv *env);
void			project(t_fdfenv *env, t_point point, t_pixel *pixel);
void			save(t_fdfenv *env);
void			drawline(t_fdfenv *env, t_pixel a, t_pixel b);
void			mapparse(t_fdfenv *env, char **strmap);
void			rotate(t_point *point, t_fpoint r);
void			ispeed(t_fdfenv *env);
void			dspeed(t_fdfenv *env);
void			icolor(t_fdfenv *env);
void			dcolor(t_fdfenv *env);
void			ibgcolor(t_fdfenv *env);
void			dbgcolor(t_fdfenv *env);
void			getcolor(t_point *point, char *str);
void			point_add(t_fdfenv *env, int x, int y, int color);
void			pixel_add(t_fdfenv *env, int x, int y, int color);
void			background(t_fdfenv *env);

#endif
