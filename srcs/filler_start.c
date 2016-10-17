/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/17 17:36:20 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	find_en_start(t_filler *filler)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < filler->y)
	{
		x = 0;
		while (x < filler->x)
		{
			if (filler->board[y][x] != filler->p - 32
					&& filler->board[y][x] != filler->p
					&& filler->board[y][x] != '.')
			{
				filler->en_start.x = x;
				filler->en_start.y = y;
			}
			++x;
		}
		++y;
	}
	filler->done = 1;
}

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
		while (i < filler->y + 1)
		{
			get_next_line(0, &buf);
			if (i > 0)
				str_array_add(&filler->board, buf + 4);
			++i;
		}
		if (!filler->done)
			find_en_start(filler);
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
			lst_max(filler);
			ft_putstr_fd("max: ", 2);
			ft_putnbr_fd(filler->lst_max, 2);
			ft_putstr_fd("\n", 2);
			ft_putstr_fd("nbr: ", 2);
			ft_putnbr_fd(lst_count_max(filler), 2);
			ft_putstr_fd("\n", 2);
			ft_putstr_fd("useless: ", 2);
			ft_putnbr_fd(lst_count_useless(filler), 2);
			ft_putstr_fd("\n\n", 2);
			str1 = ft_strjoin(ft_itoa(filler->cy), " ");
			str2 = ft_strjoin(str1, ft_itoa(filler->cx));
			str3 = ft_strjoin(str2, "\n");
			str_array_del(&filler->board);
			str_array_del(&filler->piece);
			ft_putstr(str3);
			filler->board = str_array_new();
			filler->piece = str_array_new();
			str_array_del(&filler->territory_r);
			str_array_del(&filler->board_tmp);
		}
	}
}
