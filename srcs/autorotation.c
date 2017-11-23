#include "fdf.h"

void	ispeed(t_fdfenv *env)
{
	if (env->speed < .2)
		env->speed += 0.01;
env->key = -1;
}

void	dspeed(t_fdfenv *env)
{
	if (env->speed > -.2)
		env->speed -= 0.01;
env->key = -1;
}
