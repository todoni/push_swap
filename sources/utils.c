#include <unistd.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

void	terminate(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
