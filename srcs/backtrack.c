/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:44 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/18 15:16:01 by mdos-san         ###   ########.fr       */
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
	while (x < filler->x)
	{
		y = 0;
		while (y < filler->y)
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
	return (!fail);
}
