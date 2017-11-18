#include "fdf.h"

void			left(t_fdfenv *env)
{
env->camera.a.x++;
drawpoint(env);
}
void			up(t_fdfenv *env)
{
env->camera.a.y++;
drawpoint(env);
}
void			down(t_fdfenv *env)
{
env->camera.a.y--;
drawpoint(env);
}
void			right(t_fdfenv *env)
{
env->camera.a.x--;
drawpoint(env);
}
void			higher(t_fdfenv *env)
{
env->camera.a.z++;
drawpoint(env);
}
void			lower(t_fdfenv *env)
{
env->camera.a.z--;
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
ft_printf("dezoom");
drawpoint(env);
}
