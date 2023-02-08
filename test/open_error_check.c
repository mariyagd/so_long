#include "errors.h"

void	open_error_check(int fd)
{
	if (fd < 0)
		error_msg(2);
}

