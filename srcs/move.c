#include "fdf.h"

void			left(t_fdfenv *env)
{
	env->x--;
}
void			up(t_fdfenv *env)
{
	env->y--;
}
void			down(t_fdfenv *env)
{
	env->y++;
}
void			right(t_fdfenv *env)
{
	env->x++;
}
