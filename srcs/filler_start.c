#include "filler.h"

static void	get_piece(t_filler *filler)
{
	int		i;
	char	*buf;

	i = 0;
	get_next_line(0, &filler->piece_init);
	ft_putstr_fd(filler->piece_init, 2);
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
	ft_putstr_fd("displaying piece\n", 2);
	i = 0;
	while (filler->piece[i])
	{
		ft_putstr_fd(filler->piece[i], 2);
		ft_putchar_fd('\n', 2);
		++i;
	}
	ft_putstr_fd("END==\n", 2);
}

static void	get_board(t_filler *filler)
{
	int		i;
	char	*buf;

	i = 0;
	get_next_line(0, &filler->board_init);
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
	ft_putstr_fd("displaying board\n", 2);
	i = 0;
	while (filler->board[i])
	{
		ft_putstr_fd(filler->board[i], 2);
		ft_putchar_fd('\n', 2);
		++i;
	}
	ft_putstr_fd("END==\n", 2);
}

void	filler_start(t_filler *filler)
{
	get_board(filler);
	get_piece(filler);
}
