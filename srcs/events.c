#include "fdf.h"


void			quit()
{
	exit(0);
}

int		g_button[K_NB] =
{
	113,
	104,
	106,
	107,
	108
};
void		(*g_buttonf[K_NB])() =
{
	&quit,
	&left,
	&down,
	&up,
	&right
};
int		g_key[K_NB] =
{
	113,
	104,
	106,
	107,
	108
};
void		(*g_keyf[K_NB])() =
{
	&quit,
	&left,
	&down,
	&up,
	&right
};

int			buttonpressed(int key,int x,int y, t_fdfenv *env)
{
	size_t		count;

	count = 0;
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
int	bpp;
int	s_l;
int	endian;

	count = 0;
	while(count < K_NB)
	{
		if (key == g_key[count])
			g_keyf[count](env);
		count++;
	}
}


