/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:19:51 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/18 17:31:20 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			explore(t_filler *filler)
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
	while (x < filler->x)
	{
		y = 0;
		while (y < filler->y)
		{
			if (check(filler, x, y))
			{
				fail = 0;
				str_array_cpy(filler->territory_tmp, filler->territory);
				put(filler, x, y);
				territory_control(filler);
				if (filler->max_ratio < filler->nbr_r)
				{
					filler->cx = x;
					filler->cy = y;
					filler->max_ratio = filler->nbr_r;
				}
			}
			++y;
		}
		++x;
	}
	int k;
	k = 0;
	while (filler->territory_tmp[k])
	{
		ft_putstr_fd(filler->territory_tmp[k], 2);
		ft_putstr_fd("\n", 2);
		++k;
	}
	return (!fail);
}
