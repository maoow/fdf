/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:44:58 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/23 15:46:35 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		col(char *str)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while ((ft_isdigit(str[i]) || (str[i] >= 'A' && str[i] <= 'F')
				|| (str[i] >= 'a' && str[i] <= 'f')))
	{
		if (str[i] <= '9')
			c += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			c += str[i] - 'A' + 10;
		else
			c += str[i] - 'a' + 10;
		c *= 16;
		i++;
	}
	return (c);
}

void			getcolor(t_point *point, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ',' || ft_isdigit(str[i]))
		i++;
	if (str[i] == 'x')
		point->color = col(&str[i + 1]);
	else
		exit(0);
}
