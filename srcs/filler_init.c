/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:40 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/17 15:16:26 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	filler_init(void)
{
	t_filler	new;

	get_next_line(0, &new.init);
	new.p = (new.init[10] == '1') ? 'o' : 'x';
	new.board = str_array_new();
	new.piece = str_array_new();
	new.done = 0;
	new.en_start.x = 0;
	new.en_start.y = 0;
	new.prev_o = 0;
	new.prev_x = 0;
	new.sol = NULL;
	return (new);
}
