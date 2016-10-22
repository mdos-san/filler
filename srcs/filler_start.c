/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:26:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 07:46:55 by mdos-san         ###   ########.fr       */
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

static void	territory_init(t_filler *filler)
{
	if (!filler->done)
	{
		filler->territory = str_array_dup(filler->board, 0);
		filler->territory_tmp = str_array_dup(filler->board, 0);
		filler->done = 1;
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
			(i > 0) ? str_array_add(&filler->board, buf + 4) : (void)0;
			++i;
		}
		territory_init(filler);
	}
	return (ret);
}

void		filler_start(t_filler *filler)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	exit;
	int		k;

	exit = 1;
	while (exit)
	{
		if (get_board(filler) > 0)
		{
			get_new_piece(filler);
			get_piece(filler);
			exit = explore(filler);
			str1 = ft_strjoin(ft_itoa(filler->cy), " ");
			str2 = ft_strjoin(str1, ft_itoa(filler->cx));
			str3 = ft_strjoin(str2, "\n");
			k = 0;
			ft_putstr_fd("\n", 2);
			ft_putstr(str3);
			str_array_del(&filler->board);
			filler->board = str_array_new();
			filler->piece = str_array_new();
		}
	}
}
