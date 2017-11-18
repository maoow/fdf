#include "fdf.h"

void		drawline(t_fdfenv *env, t_pixel a, t_pixel b)
{
	t_pixel	pen;
	t_pixel	target;
	t_pixel	dir;
	t_pixel	mod;
	size_t	i;

	i = 0;
	pen.x = 0;
	pen.y = 0;
	dir.x = 1;
	dir.y = 1;
	mod.x = 1;
	mod.y = 1;
	target.x = b.x - a.x;
	target.y = b.y - a.y;
	if (target.x < 0)
		dir.x = -1;
	if (target.y < 0)
		dir.y = -1;
	if (abs(target.x) > abs(target.y) && abs(target.y))
		mod.y = abs(target.x) / abs(target.y);
	else if (abs(target.x))
		mod.x = abs(target.y) / abs(target.x);
if (mod.x == 0)
		mod.x = 1;
if (mod.y == 0)
		mod.y = 1;
	while (target.x != pen.x || target.y != pen.y)
	{
		if (i % mod.x == 0 && pen.x != target.x)
			pen.x += dir.x;
		if (i % mod.y == 0 && pen.y != target.y)
			pen.y += dir.y;
		i++;
		mlx_pixel_put(env->mlx, env->win, a.x + pen.x, a.y + pen.y, 0x00FFFFFF);
	}
}

