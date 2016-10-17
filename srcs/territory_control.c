/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:30:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/17 18:09:06 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	control(t_filler *filler, int i, int j, char nb)
{
	int		x;
	int		y;
	int		rx;
	int		ry;
	char	a;
	char	c;
	char	lc;
	char	stop;
	int		depth;

	stop = 0;
	depth = 1;
	c = (nb == 1) ? 'x' : 'o';
	lc = c - 32;
	while (stop == 0)
	{
		y = -depth;
		while (y <= depth && !stop)
		{
			x = -depth;
			ry = j + y;
			while (x <= depth && !stop)
			{
				if (x == -depth || x == depth || y == -depth || y == depth)
				{
					rx = i + x;
					if (rx >= 0 && ry >= 0 && rx < filler->x && ry < filler->y)
					{
						a = filler->territory_r[ry][rx];
						if (a == '.')
							filler->territory_r[ry][rx] = nb + 48;
						else if (a == c || a == lc)
							stop = 1;
						else if (a != nb + 48)
							filler->territory_r[ry][rx] = '.';
					}
				}
				++x;
			}
			++y;
		}
		++depth;
	}
}

static void	get_territory(t_filler *filler)
{
	int		i;
	int		j;
	char	c;
	char	a;
	char	stop;

	j = 0;
	stop = 0;
	while (j < filler->y)
	{
		i = 0;
		while (i < filler->x)
		{
			a = filler->territory_r[j][i];
			if (a == 'o' || a == 'O')
				control(filler, i, j, 1);
			else if (a == 'x' || a == 'X')
				control(filler, i, j, 2);
			++i;
		}
		++j;
	}
}

static void	count_territory(t_filler *filler)
{
	int	x;
	int	y;
	char	a;

	y = 0;
	filler->nbr_o = 0;
	filler->nbr_x = 0;
	while (y < filler->y)
	{
		x = 0;
		while (x < filler->x)
		{
			a = filler->territory_r[y][x];
			if (a == '1' || a == 'o' || a == 'O')	
				++filler->nbr_o;
			if (a == '2' || a == 'x' || a == 'X')	
				++filler->nbr_x;
			++x;
		}
		++y;
	}
}

void	territory_control(t_filler *filler)
{
	int	i;
	int	j;

	j = 0;
	get_territory(filler);
	count_territory(filler);
	filler->nbr_r = (filler->p == 'o')
		? ((double)filler->nbr_o / (double)filler->nbr_x)
		: ((double)filler->nbr_x / (double)filler->nbr_o);
}
