#include "fdf.h"

void			mouserotate(t_fdfenv *env)
{
if (env->key == 3)
{
	env->rotate.y -= ((float)env->mouse.x - (float)env->width / 2) / 1000;
	env->rotate.x += ((float)env->mouse.y - (float)env->height / 2) / 1000;
	drawpoint(env);
}
}
void			center(t_fdfenv *env)
{
env->camera.a.x += env->mouse.x - env->width / 2;
env->camera.a.y += env->mouse.y - env->height / 2;
drawpoint(env);
}
void			left(t_fdfenv *env)
{
env->camera.a.x+= 10;
drawpoint(env);
}
void			up(t_fdfenv *env)
{
env->camera.a.y+= 10;
drawpoint(env);
}
void			down(t_fdfenv *env)
{
env->camera.a.y-= 10;
drawpoint(env);
}
void			right(t_fdfenv *env)
{
env->camera.a.x-= 10;
drawpoint(env);
}
void			higher(t_fdfenv *env)
{
env->top++;
drawpoint(env);
}
void			lower(t_fdfenv *env)
{
if (env->top != 1)
env->top--;
drawpoint(env);
}
void			zoom(t_fdfenv *env)
{
env->zoom++;
drawpoint(env);
}
void			dezoom(t_fdfenv *env)
{
if (env->zoom > 1)
env->zoom--;
drawpoint(env);
}
