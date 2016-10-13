/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/13 16:26:36 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_piece(t_filler *filler)
{
	int		i;
	char	*buf;

	i = 0;
	get_next_line(0, &filler->piece_init);
	while (filler->piece_init[i] != ' ')
		++i;
	filler->py = ft_atoi(filler->piece_init + ++i);
	while (filler->piece_init[i] != ' ')
		++i;
	filler->px = ft_atoi(filler->piece_init + ++i);
	i = 0;
	while (i < filler->py)
	{
		get_next_line(0, &buf);
		str_array_add(&filler->piece, buf);
		++i;
	}
}

static int	get_board(t_filler *filler)
{
	int		i;
	char	*buf;
	int		ret;

	i = 0;
	ret = get_next_line(0, &filler->board_init);
	if (ret > 0)
	{
		while (filler->board_init[i] != ' ')
			++i;
		filler->y = ft_atoi(filler->board_init + ++i);
		while (filler->board_init[i] != ' ')
			++i;
		filler->x = ft_atoi(filler->board_init + ++i);
		i = 0;
		while (i <= filler->y)
		{
			get_next_line(0, &buf);
			str_array_add(&filler->board, buf);
			++i;
		}
	}
	return (ret);
}

void	filler_start(t_filler *filler)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	exit;

	exit = 1;
	while (exit)
	{
		if (get_board(filler) > 0)
		{
			get_piece(filler);
			exit = backtrack(filler);
			str1 = ft_strjoin(ft_itoa(filler->cy), " ");
			str2 = ft_strjoin(str1, ft_itoa(filler->cx));
			str3 = ft_strjoin(str2, "\n");
			str_array_del(&filler->board);
			str_array_del(&filler->piece);
			filler->board = str_array_new();
			filler->piece = str_array_new();
			ft_putstr(str3);
		}
	}
}
