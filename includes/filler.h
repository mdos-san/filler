#ifndef FILLER_H
# define FILLER_H
# define OFF_Y 1
# define OFF_X 4
# include "libft.h"

typedef struct	s_pnt
{
	int			x;
	int			y;
}				t_pnt;

typedef struct	s_solution
{
	int			x;
	int			y;
	int			nbr_o;
	int			nbr_x;
	int			ratio;
}				t_solution;

typedef struct	s_filler
{
	int			log_fd;
	char		*init;
	char		p;
	char		*board_init;
	int			x;
	int			y;
	char		**board;
	char		**board_tmp;
	char		**territory_r;
	int			nbr_o;
	int			nbr_x;
	double		nbr_r;
	int			prev_o;
	int			prev_x;
	char		*piece_init;
	int			px;
	int			py;
	char		**piece;
	int			cx;
	int			cy;
	int			ratio;
	int			max_ratio;
	t_pnt		en_start;
	char		done;	
	t_list		sol;
}				t_filler;

t_filler	filler_init(void);
void		filler_start(t_filler *filler);
int			backtrack(t_filler *filler);
int			check(t_filler *filler, int x, int y);
void		territory_control(t_filler *filler);
void		put(t_filler *filler, int x, int y);

#endif
