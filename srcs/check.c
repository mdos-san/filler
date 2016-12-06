/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:58:04 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 07:40:08 by mdos-san         ###   ########.fr       */
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

	tx = 0;
	connected = 0;
	while (tx < filler->px && tx + x < filler->x)
	{
		ty = 0;
		while (ty < filler->py && ty + y < filler->y)
		{
			c = filler->board[ty + y][tx + x];
			p = filler->piece[ty][tx];
			if ((c == filler->p || c == filler->p - 32) && p == '*')
				++connected;
			else if (c != '.' && p == '*')
				return (0);
			++ty;
		}
		++tx;
	}
	return ((connected == 1 && x + filler->px - 1 < filler->x
		&& y + filler->py - 1 < filler->y) ? 1 : 0);
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
