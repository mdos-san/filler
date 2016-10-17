/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:44 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/17 17:57:22 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			backtrack(t_filler *filler)
{
	int	x;
	int	y;
	int	fail;
	int	en;
	t_solution s;

	x = 0;
	fail = 1;
	filler->cx = 0;
	filler->cy = 0;
	filler->max_ratio = 0;
	filler->board_tmp = str_array_dup(filler->board, 0);
	filler->territory_r = str_array_dup(filler->board_tmp, 0);
	territory_control(filler);
	filler->prev_o = filler->nbr_o;
	filler->prev_x = filler->nbr_x;
	filler->min_en = (filler->p == 'o') ? filler->nbr_x : filler->nbr_o;
	filler->sol = NULL;
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
				en = (filler->p == 'o') ? filler->nbr_x : filler->nbr_o;
				if (filler->nbr_r >= filler->max_ratio)
				{
					fail = 0;
					filler->cx = x;
					filler->cy = y;
					filler->max_ratio = filler->nbr_r;
					s.x = x;
					s.y = y;
					s.nbr_o = filler->nbr_o;
					s.nbr_x = filler->nbr_x;
					s.ratio = filler->nbr_r;
					(filler->sol == NULL)
						? (filler->sol = ft_lstnew((void *)&s, sizeof(t_solution)))
						: ft_lstpushb(filler->sol, (void *)&s, sizeof(t_solution));
				}
			}
			++y;
		}
		++x;
	}
	return (!fail);
}
