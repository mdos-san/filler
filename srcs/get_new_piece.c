/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:48:09 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/18 16:05:57 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_new_piece(t_filler *filler)
{
	int	x;
	int	y;

	y = 0;
	while (y < filler->y)
	{
		x = 0;
		while (x < filler->x)
		{
			if (filler->board[y][x] == 'O' && filler->territory[y][x] != '3')
				filler->territory[y][x] = 'o';
			if (filler->board[y][x] == 'X' && filler->territory[y][x] != '4')
				filler->territory[y][x] = 'x';
			if (filler->territory[y][x] == ' ')
				filler->territory[y][x] = '.';
			++x;
		}
		++y;
	}
}
