#include "errors.h"

void	extension_check(char *s)
{
	char	*s1 = ".ber";

	while (*s && *s != '.')
		s++;
	if (*s == '\0')
		error_msg(3);
	if (ft_strlen(s) != 4)
		error_msg(3);
	if (ft_strncmp(s, s1, 4) != 0)
		error_msg(3);
}
	
