/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:58:04 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/15 18:25:59 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check(t_filler *filler, int x, int y)
{
	int		tx;
	int		ty;
	int		connected;
	char	c;
	char	p;

	tx = 0;
	connected = 0;
	if (!(0 <= x && x < filler->x) || !(0 <= y && y < filler->y))
		return (0);
	while (tx < filler->px && tx + x < filler->x)
	{
		ty = 0;
		while (ty < filler->py && ty + y < filler->y)
		{
			c = filler->board[y + ty][x + tx];
			p = filler->piece[ty][tx];
			if ((c == filler->p || c == filler->p - 32) && p == '*')
				++connected;
			else if (c != '.' && p == '*')
				return (0);
			++ty;
		}	
		++tx;
	}
	if (connected == 1 && tx + x < filler->x && ty + y < filler->y)
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
				filler->board_tmp[y + ty][x + tx] = filler->p;
			++ty;
		}	
		++tx;
	}
}
