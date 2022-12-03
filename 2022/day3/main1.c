#include "get_next_line.h"
//
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

static int	check_line(char *line, char dict[255][2], size_t len)
{
	size_t	i;
	int		cnt;

	i = -1;
	while (++i < len / 2)
	{
		cnt = line[i];
		if (cnt == 10)
			break ;
		if (islower(cnt))
			cnt -= 96;
		else 
			cnt -= 38;
		dict[cnt][0] = 1;
	}
	while (i < len)
	{
		cnt = line[i];
		if (cnt == 10)
			break ;
		if (islower(cnt))
			cnt -= 96;
		else
			cnt -= 38;
		if (dict[cnt][0] == 1)
		{
			fprintf(stderr, "%d\n", cnt);
			return (cnt);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char *av[]) {
	
	(void)ac;
	(void)av;
	char	*line;
	char	dict[255][2];
	size_t	len;
	int		fd;
	int		sum;

	//fd = open("test_output.txt", O_RDONLY);
	fd = open("output.txt", O_RDONLY);
	sum = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = strlen(line);
		memset(&dict, 0, sizeof(dict));
		sum += check_line(line, dict, len);
	}
	fprintf(stderr, "SUM: %d\n", sum);
	return 0;
}

