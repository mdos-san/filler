/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:44 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/17 15:01:47 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			backtrack(t_filler *filler)
{
	int	x;
	int	y;
	int	fail;

	x = 0;
	fail = 1;
	filler->cx = 0;
	filler->cy = 0;
	filler->max_ratio = 0;
	filler->board_tmp = str_array_dup(filler->board, 0);
	filler->territory_r = str_array_dup(filler->board_tmp, 0);
	while (x < filler->x)
	{
		y = 0;
		while (y < filler->y)
		{
			if (check(filler, x, y))
			{
				str_array_cpy(filler->board_tmp, filler->board);
				put(filler, x, y);
				str_array_cpy(filler->territory_r, filler->board_tmp);
				territory_control(filler);
				if (filler->ratio > filler->max_ratio)
				{
					fail = 0;
					filler->cx = x;
					filler->cy = y;
					if (filler->prev_o == filler->nbr_o && filler->prev_x == filler->nbr_x)
					{
						ft_putstr_fd("Useless\n", 2)
					}
					else
					{
						filler->prev_o = filler->nbr_o;
						filler->prev_x = filler->nbr_x;
					}
					filler->max_ratio = filler->ratio;
				}
			}
			++y;
		}
		++x;
	}
	return (!fail);
}
