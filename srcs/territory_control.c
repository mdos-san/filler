/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:30:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/19 16:50:52 by mdos-san         ###   ########.fr       */
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
	int		enb;

	stop = 0;
	depth = 1;
	c = (nb == 1) ? 'x' : 'o';
	enb = (nb == 1) ? 2 : 1;
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
						a = filler->territory_tmp[ry][rx];
						if (a == '.')
							filler->territory_tmp[ry][rx] = nb + 48;
						else if (a == c || a == lc || a == enb + 2 + 48)
							stop = 1;
						else if (a == enb + 48)
							filler->territory_tmp[ry][rx] = ' ';
					}
				}
				++x;
			}
			++y;
		}
		++depth;
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
			if (filler->territory_tmp[y][x] == '.')
				filler->territory_tmp[y][x] = (filler->p == 'o') ? '2' : '1';
			++x;
		}
		++y;
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
			++i;
		}
		++j;
	}
	//get_empty(filler);
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
			a = filler->territory_tmp[y][x];
			if (a == '1' || a == '3')	
				++filler->nbr_o;
			if (a == '2' || a == '4')	
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
	int	k;

	j = 0;
	k = 0;
	get_territory(filler);
	count_territory(filler);
	filler->nbr_r = (filler->p == 'o')
		? ((double)filler->nbr_o / (double)filler->nbr_x)
		: ((double)filler->nbr_x / (double)filler->nbr_o);
}
