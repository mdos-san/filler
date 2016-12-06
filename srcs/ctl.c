/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:37:45 by mdos-san          #+#    #+#             */
/*   Updated: 2016/11/30 18:38:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ctl(t_filler *filler, int i, char nb, t_control *c)
{
	if (c->x == -c->depth || c->x == c->depth
			|| c->y == -c->depth || c->y == c->depth)
	{
		c->rx = i + c->x;
		if (c->rx >= 0 && c->ry >= 0 && c->rx < filler->x && c->ry < filler->y)
		{
			c->a = filler->territory_tmp[c->ry][c->rx];
			if (c->a == '.')
				filler->territory_tmp[c->ry][c->rx] = nb + 48;
			else if (c->a == c->c || c->a == c->lc || c->a == c->enb + 2 + 48)
				c->stop = 1;
			else if (c->a == c->enb + 48)
				filler->territory_tmp[c->ry][c->rx] = ' ';
		}
	}
	++c->x;
}
