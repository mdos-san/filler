/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 01:46:30 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 01:47:27 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	double		ratio;
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
	char		**territory;
	char		**territory_tmp;
	int			nbr_o;
	int			nbr_x;
	double		nbr_r;
	double		max_ratio;
	int			prev_o;
	int			prev_x;
	char		*piece_init;
	int			px;
	int			py;
	char		**piece;
	int			cx;
	int			cy;
	t_pnt		en_start;
	char		done;
	t_list		*sol;
	double		lst_max;
	int			lst_useless;
	int			min_en;
	int			counter;
}				t_filler;

t_filler		filler_init(void);
void			filler_start(t_filler *filler);
int				explore(t_filler *filler);
int				find_by_distance(t_filler *filler, int depth);
int				check(t_filler *filler, int x, int y);
void			territory_control(t_filler *filler);
void			put(t_filler *filler, int x, int y);
void			lst_max(t_filler *filler);
int				lst_count_max(t_filler *filler);
int				lst_count_useless(t_filler *filler);
void			get_new_piece(t_filler *filler);

#endif
