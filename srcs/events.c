#include "fdf.h"


void			quit(t_fdfenv *env)
{
save(env);
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
	&selectpoint,
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
	97,
	115,
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
	&higherpoint,
	&lowerpoint,
	&smoother
};

int			loop(int key,int x,int y, t_fdfenv *env)
{
	printf("x: %f y: %f z: %f\nzoom: %d\n\n", env->rotate.x, env->rotate.y, env->rotate.z,env->zoom);
return (0);
}
int			loopachieved(t_fdfenv *env)
{
	if (env->key == 0)
	{
		env->rotate.z += 0.02 / env->zoom;
		drawpoint(env);
	}
//	printf("x: %f y: %f z: %f\nzoom: %d\n\n", env->rotate.x, env->rotate.y, env->rotate.z,env->zoom);
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
drawpoint(env);
}

int			keypressed(int key, t_fdfenv *env)
{
	size_t		count;

	count = 0;
//ft_printf("yo");
	env->key = key;
	while(count < K_NB && key != g_key[count])
		count++;
	if (count < K_NB)
		g_keyf[count](env);
	else
		env->key = 0;
ft_printf("%d\n", key);
drawpoint(env);
}


