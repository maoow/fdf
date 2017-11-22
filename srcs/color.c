#include "fdf.h"


void	icolor(t_fdfenv *env)
{
	if (env->y >= 0 && env->y < env->mapsize.y && env->x >= 0 && env->x < env->mapsize.x)
	{
		if (env->map[env->x][env->y].color <= 0x100000)
			env->map[env->x][env->y].color *= 0x2;
		else 
			env->map[env->x][env->y].color = 0xff0000;
	}
}
void	dcolor(t_fdfenv *env)
{
	if (env->y >= 0 && env->y < env->mapsize.y && env->x >= 0 && env->x < env->mapsize.x)
	{
		if (env->map[env->x][env->y].color >= 0x10)
			env->map[env->x][env->y].color /= 0x2;
		else 
			env->map[env->x][env->y].color = 0x10;
	}
}

void	ibgcolor(t_fdfenv *env)
{
			env->color *= 0x2;
		if (env->color > 0x100000)
			env->color = 0xff0000;
}
void	dbgcolor(t_fdfenv *env)
{
			env->color /= 0x2;
		if (env->color < 0x10)
			env->color = 0x10;
}
