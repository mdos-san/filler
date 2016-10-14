/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_by_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:55:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/14 15:32:18 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int find_by_distance(t_filler *filler, int depth)
{
	int x;
	int y;
	t_pnt   pos;
	int cx;
	int cy;

	y = - depth;
	pos = filler->en_start;
	if (depth > filler->x && depth > filler->y)
		return (0);
	while (y <= depth)
	{
		x = - depth;
		cy = pos.y + y;
		while (x <= depth)
		{ 
			cx = pos.x + x;
			if (check(filler, cx, cy))
			{
				filler->cx = cx;
				filler->cy = cy;
				return (1);
			}
			++x;
		}
		++y;
	}
	return (find_by_distance(filler, depth + 1));
}