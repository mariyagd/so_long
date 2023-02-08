#include "errors.h"
#include "../libft/includes/libft.h"

void	fill_tab2d(char **tab2d, int fd, int size_y)
{
	char	*buf;
	int		i;

	i = 0;
	buf = NULL;
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		ft_memcpy(tab2d[i], buf, size_y);
		free(buf);
		buf = NULL;
		buf = get_next_line(fd);
		i++;
	}
}

char	**malloc_tab2d(int size_x, int size_y)
{
	int		i;
	char 	**tab2d;

	i = 0;
	tab2d = (char **)ft_calloc((size_x + 1), sizeof(char *));
	if (!tab2d)
		error_msg(6);
	while (i < size_x)
	{
		tab2d[i] = (char *)ft_calloc((size_y + 1), sizeof(char));
		if (!tab2d[i])
		{
			i = 0;
			while (tab2d[i] != NULL)
			{
				free(tab2d[i]);
				i++;
			}
			free(tab2d);
			error_msg(6);
		}
		i++;
	}
	return (tab2d);
}

char	**create_bidimensional_tab(int size_x, int size_y, char **av)
{
	char	**tab2d = NULL;
	int		fd;

	tab2d = malloc_tab2d(size_x, size_y);
	fd = open(*av, O_RDONLY);
	open_error_check(fd);
	fill_tab2d(tab2d, fd, size_y);
	return (tab2d);
}

void	copy_string(char **dst, char *src)
{
	int	i;

	i = 0;
	while(src[i] != '\n')
	{
		*dst[i] = src[i];
		i++;
	}
	*dst[i] = '\0';
}


void	prepare_bidimensional_tab(int fd, char **av)
{
	char	*buf;
	char	**tab2d;
	int		size_y;
	int		size_x;
	
	buf = NULL;
	tab2d = NULL; 
	size_y = 0;
	size_x = 0;
	buf = get_next_line(fd);
	size_y = ft_strlen_int(buf) - 1;
	while (buf != NULL)
	{
		if (buf != NULL && ft_strlen_int(buf) - 1 != size_y)
		{
			free(buf);
			error_msg(4);
		}
		size_x++;
		free(buf);
		buf = NULL;
		buf = get_next_line(fd);
	}
	if (size_x == size_y)
		error_msg(5);
	close(fd);
	tab2d = create_bidimensional_tab(size_x, size_y, av);
	map_checker(tab2d, size_x, size_y);
}

