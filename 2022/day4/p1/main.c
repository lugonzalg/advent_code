#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"
#include "libft.h"

static void	free_tab(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static void	set_range(char *line, int range[2][2])
{
	char	**tab;
	char	**tmp;

	tab = ft_split(line, ',');
	tmp = tab;
	tab = ft_split(tmp[0], '-');
	range[0][0] = atoi(tab[0]);
	range[0][1] = atoi(tab[1]);
	free_tab(tab);
	tab = ft_split(tmp[1], '-');
	range[1][0] = atoi(tab[0]);
	range[1][1] = atoi(tab[1]);
	free_tab(tab);
	free_tab(tmp);
}

static int	range_domain(int range[2][2])
{
	if (range[0][0] >= range[1][0] && range[0][1] <= range[1][1])
		return (1);
	if (range[1][0] >= range[0][0] && range[1][1] <= range[0][1])
		return (1);
	return (0);
}

int	main(int ac, char *av[]) {
	
	(void)ac;
	(void)av;
	char	*line;
	int		fd;
	int		range[2][2];
	int		sum;

	//fd = open("test_output.txt", O_RDONLY);
	fd = open("output.txt", O_RDONLY);
	sum = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		//fprintf(stderr, "LINE: %s\n", line);
		set_range(line, range);
		sum += range_domain(range);
		free(line);
	}
	fprintf(stderr, "RESULT: %d\n", sum);
	return 0;
}

