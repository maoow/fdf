#include "fdf.h"

void	save(t_fdfenv *env)
{
	int	fd;
	int	i;
	int	j;
	char *str;

	fd = open("./save.fdf", O_WRONLY);
	i = 0;
if (fd > 0)
	while (i < env->mapsize.y)
	{
		j = 0;
		while (j < env->mapsize.x)
		{
			write(fd, ft_itoa(env->map[i][j].z),ft_strlen(ft_itoa(env->map[i][j].z)));
			write(fd, ",0x", 3);
str = ft_itoabase(env->map[i][j].color % 0x1000000,"012345679abcdef");
write(fd, str, ft_strlen(str));
			j++;
			write(fd, " ", 1);
		}
			write(fd, "\n", 1);
		i++;
	}
	close(fd);
}
