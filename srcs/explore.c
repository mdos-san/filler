/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:19:51 by mdos-san          #+#    #+#             */
/*   Updated: 2016/11/30 18:32:44 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	exec(t_filler *filler, int x, int y, int *fail)
{
	if (check(filler, x, y))
	{
		*fail = 0;
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
}

static void	debug(t_filler *filler)
{
	int	k;

	k = 0;
	while (filler->territory[k])
	{
		ft_putstr_fd(filler->territory[k], 2);
		ft_putstr_fd("\n", 2);
		++k;
	}
}

int			explore(t_filler *filler)
{
	int			x;
	int			y;
	int			fail;

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
			exec(filler, x, y, &fail);
			++y;
		}
		++x;
	}
	if (filler->x * filler->y > 50 * 50)
		str_array_cpy(filler->territory, filler->territory_tmp);
	if (filler->debug)
		debug(filler);
	return (!fail);
}
