#include "fdf.h"

void			mouserotate(t_fdfenv *env)
{
	if (env->key == 3)
	{
		env->rotate.z -= ((float)env->mouse.x - (float)env->width / 2) / env->width;
		env->rotate.x += ((float)env->mouse.y - (float)env->height / 2) / env->height;
	}
}
void			center(t_fdfenv *env)
{
	env->camera.a.x += env->mouse.x - env->width / 2;
	env->camera.a.y += env->mouse.y - env->height / 2;
}
void			selectpoint(t_fdfenv *env)
{
	t_pixel tmp;
	t_pixel diff;
	int	i;
	int	j;

	i =0 ;
	while (i < env->mapsize.y)
	{
		j = 0;
		while (j < env->mapsize.x)
		{
			project(env, env->map[i][j], &tmp);
			diff.x = env->mouse.x - tmp.x;
			diff.y = env->mouse.y - tmp.y;
			if (diff.x <  5 && diff.x > -5 && diff.y < 5 && diff.y > -5)
			{
				env->x = i;
				env->y = j;
			}
			j++;
		}
		i++;
	}
}
void			left(t_fdfenv *env)
{
	env->camera.a.x+= 10;
}
void			up(t_fdfenv *env)
{
	env->camera.a.y+= 10;
}
void			down(t_fdfenv *env)
{
	env->camera.a.y-= 10;
}
void			right(t_fdfenv *env)
{
	env->camera.a.x-= 10;
}
void			higherpoint(t_fdfenv *env)
{
	env->map[env->x][env->y].z++;
}
void			higher(t_fdfenv *env)
{
	env->top++;
}
void			lowerpoint(t_fdfenv *env)
{
	env->map[env->x][env->y].z--;
}
void			lower(t_fdfenv *env)
{
	env->top--;
}
void			zoom(t_fdfenv *env)
{
	env->zoom++;
}
void			dezoom(t_fdfenv *env)
{
	if (env->zoom > 1)
		env->zoom--;
}
void			harder(t_fdfenv *env)
{
	if (env->smooth > 1)
		env->smooth--;
}
void			smoother(t_fdfenv *env)
{
	env->smooth++;
}
