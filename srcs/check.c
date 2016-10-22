/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:58:04 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 01:40:52 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(t_filler *filler, int x, int y)
{
	int		tx;
	int		ty;
	int		connected;
	char	c;
	char	p;
	int		r_x;
	int		r_y;

	tx = 0;
	connected = 0;
	while (tx < filler->px && tx + x < filler->x)
	{
		ty = 0;
		r_x = tx + x;
		r_y = y;
		while (ty < filler->py && r_y < filler->y)
		{
			c = filler->board[r_y][r_x];
			p = filler->piece[ty][tx];
			if ((c == filler->p || c == filler->p - 32) && p == '*')
				++connected;
			else if (c != '.' && p == '*')
				return (0);
			++ty;
			r_y = ty + y;
		}
		++tx;
	}
	if (connected == 1 && x + filler->px - 1 < filler->x
		&& y + filler->py - 1 < filler->y)
		return (1);
	else
		return (0);
}

void	put(t_filler *filler, int x, int y)
{
	int		tx;
	int		ty;
	char	p;

	tx = 0;
	while (tx < filler->px && tx + x < filler->x)
	{
		ty = 0;
		while (ty < filler->py && ty + y < filler->y)
		{
			p = filler->piece[ty][tx];
			if (p == '*')
				filler->territory_tmp[y + ty][x + tx] = filler->p;
			++ty;
		}	
		++tx;
	}
}
