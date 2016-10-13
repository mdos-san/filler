/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:44 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/13 16:33:04 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check(t_filler *filler, int x, int y)
{
	int		tx;
	int		ty;
	int		connected;
	char	c;
	char	p;


	tx = 0;
	connected = 0;
	while (tx < filler->px && tx + x < filler->x)
	{
		ty = 0;
		while (ty < filler->py && ty + y < filler->y)
		{
			c = filler->board[y + OFF_Y + ty][x + OFF_X + tx];
			p = filler->piece[ty][tx];
			if ((c == filler->p || c == filler->p - 32) && p == '*')
				++connected;
			else if (c != '.' && p == '*')
				return (0);
			++ty;
		}	
		++tx;
	}
	if (connected == 1)
		return (1);
	else
		return (0);
}

int			backtrack(t_filler *filler)
{
	int	x;
	int	y;

	x = 0;
	filler->cx = 0;
	filler->cy = 0;
	while (x + filler->px - 1 < filler->x)
	{
		y = 0;
		while (y + filler->py - 1 < filler->y)
		{
			if (check(filler, x, y))
			{
				filler->cx = x;
				filler->cy = y;
				return (1);
			}
			++y;
		}
		++x;
	}
	return (0);
}
