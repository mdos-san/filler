#include "filler.h"

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
	while (i < filler->y)
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

}
