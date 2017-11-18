#include "fdf.h"


void			quit()
{
	exit(0);
}

int		g_button[B_NB] =
{
	3,
	4,
	5,
	1,
	108
};
void		(*g_buttonf[B_NB])() =
{
	&mouserotate,
	&zoom,
	&dezoom,
	&center,
	&right
};

int		g_key[K_NB] =
{
	113,
	104,
	106,
	107,
	108,
	102,
	100,
	110,
	109,
	117,
	121,
	111,
	55,
	56,
	105,
	101,
	114
};
void		(*g_keyf[K_NB])() =
{
	&quit,
	&left,
	&down,
	&up,
	&right,
	&higher,
	&lower,
	&zoom,
	&dezoom,
	&maprotate,
	&maprotate,
	&maprotate,
	&maprotate,
	&maprotate,
	&maprotate,
	&harder,
	&smoother
};

int			loopachieved(t_fdfenv *env)
{
if (env->key == 0)
env->rotate.z += 0.001;
	drawpoint(env);
printf("x: %f y: %f z: %f\nzoom: %d\n\n", env->rotate.x, env->rotate.y, env->rotate.z,env->zoom);
}
int			buttonpressed(int key,int x,int y, t_fdfenv *env)
{
	size_t		count;

	count = 0;
	env->mouse.x = x;
	env->mouse.y = y;
	env->key = key;
	while(count < K_NB)
	{
		if (key == g_button[count])
			g_buttonf[count](env);
		count++;
	}
}

int			keypressed(int key, t_fdfenv *env)
{
	size_t		count;

	count = 0;
	env->key = key;
	while(count < K_NB)
	{
		if (key == g_key[count])
			g_keyf[count](env);
		count++;
	}
}


