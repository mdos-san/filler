#include "filler.h"

t_filler	filler_init(void)
{
	t_filler	new;

	get_next_line(0, &new.init);
	return (new);
}
