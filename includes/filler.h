#ifndef FILLER_H
# define FILLER_H
# define OFF_Y 1
# define OFF_X 4
# include "libft.h"

typedef struct	s_pnt
{
	int	x;
	int	y;
}				t_pnt;

typedef struct	s_filler
{
	int			log_fd;
	char		*init;
	char		p;
	char		*board_init;
	int			x;
	int			y;
	char		**board;
	char		**territory_o;
	char		**territory_x;
	char		**territory_r;
	char		*piece_init;
	int			px;
	int			py;
	char		**piece;
	int			cx;
	int			cy;
	t_pnt		en_start;
	char		done;	
}				t_filler;

t_filler	filler_init(void);
void		filler_start(t_filler *filler);
int			backtrack(t_filler *filler);
int			check(t_filler *filler, int x, int y);
int 		find_by_distance(t_filler *filler, int depth);
void		territory_control(t_filler *filler);

#endif
