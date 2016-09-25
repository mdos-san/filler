#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct	s_filler
{
	int			log_fd;
	char		*init;
}				t_filler;

t_filler	filler_init(void);

#endif
