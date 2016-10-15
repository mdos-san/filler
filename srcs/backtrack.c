/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:44 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/15 18:36:04 by mdos-san         ###   ########.fr       */
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
	while (x < filler->x)
	{
		y = 0;
		while (y < filler->y)
		{
			if (check(filler, x, y))
			{
				filler->board_tmp = str_array_dup(filler->board, 0);
				put(filler, x, y);
				filler->territory_o = str_array_dup(filler->board_tmp, 0);
				filler->territory_x = str_array_dup(filler->board_tmp, 0);
				filler->territory_r = str_array_dup(filler->board_tmp, 0);
				territory_control(filler);
				if (filler->ratio > filler->max_ratio)
				{
					fail = 0;
					filler->cx = x;
					filler->cy = y;
					filler->max_ratio = filler->ratio;
				}
				str_array_del(&filler->territory_o);
				str_array_del(&filler->territory_x);
				str_array_del(&filler->territory_r);
				str_array_del(&filler->board_tmp);
			}
			++y;
		}
		++x;
	}
	return (!fail);
}
