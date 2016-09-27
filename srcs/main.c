#include  "filler.h"

int	main()
{
	t_filler	filler;

	filler = filler_init();
	filler_start(&filler);
	return (0);
}
