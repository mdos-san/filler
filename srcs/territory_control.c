/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:30:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/12/06 07:38:02 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	control(t_filler *filler, int i, int j, char nb)
{
	t_control	c;

	c.stop = 0;
	c.depth = 1;
	c.c = (nb == 1) ? 'x' : 'o';
	c.enb = (nb == 1) ? 2 : 1;
	c.lc = c.c - 32;
	while (c.stop == 0)
	{
		c.y = -c.depth;
		while (c.y <= c.depth && !c.stop)
		{
			c.x = -c.depth;
			c.ry = j + c.y;
			while (c.x <= c.depth && !c.stop)
				ctl(filler, i, nb, &c);
			++c.y;
		}
		++c.depth;
	}
}

static void	get_empty(t_filler *filler)
{
	int	x;
	int	y;

	y = 0;
	while (y < filler->y)
	{
		x = 0;
		while (x < filler->x)
		{
			if (filler->territory_tmp[y][x] == ' ')
				filler->territory_tmp[y][x] = '.';
			++x;
		}
		++y;
	}
}

static void	get_territory(t_filler *filler)
{
	int		i;
	int		j;
	char	a;

	j = -1;
	while (++j < filler->y)
	{
		i = -1;
		while (++i < filler->x)
		{
			a = filler->territory_tmp[j][i];
			if (a == 'o' || a == 'O')
			{
				control(filler, i, j, 1);
				filler->territory_tmp[j][i] = '3';
			}
			else if (a == 'x' || a == 'X')
			{
				control(filler, i, j, 2);
				filler->territory_tmp[j][i] = '4';
			}
		}
	}
	get_empty(filler);
}

static void	count_territory(t_filler *filler)
{
	int		x;
	int		y;
	char	a;

	y = 0;
	filler->nbr_o = 0;
	filler->nbr_x = 0;
	while (y < filler->y)
	{
		x = 0;
		while (x < filler->x)
		{
			a = filler->territory_tmp[y][x];
			if (a == '1' || a == '3')
				++filler->nbr_o;
			else if (a == '2' || a == '4')
				++filler->nbr_x;
			++x;
		}
		++y;
	}
}

void		territory_control(t_filler *filler)
{
	get_territory(filler);
	count_territory(filler);
	filler->nbr_r = (filler->p == 'o')
		? ((double)filler->nbr_o / (double)filler->nbr_x)
		: ((double)filler->nbr_x / (double)filler->nbr_o);
}
