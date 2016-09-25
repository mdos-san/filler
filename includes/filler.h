#ifndef FILLER_H
# define FILLER_H

typedef struct	s_filler
{
	int			log_fd;
	char		*init;
}				t_filler;

t_filler	filler_init(void);

#endif
