#include "filler.h"

t_filler	filler_init(void)
{
	t_filler	new;

	get_next_line(0, &new.init);
	new.p = (new.init[10] == '1') ? 'o' : 'x';
	new.board = str_array_new();
	return (new);
}
