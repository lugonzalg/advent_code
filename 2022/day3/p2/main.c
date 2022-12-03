#include "get_next_line.h"
//
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

static void	check_line(char *line, char dict[255][2], size_t len, int flag)
{
	size_t	i;
	int		cnt;

	i = -1;
	while (++i < len )
	{
		cnt = line[i];
		if (islower(cnt))
			cnt -= 96;
		else 
			cnt -= 38;
		if (dict[cnt][0] == flag)
			dict[cnt][0]++;
	}
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
	fd = open("test_output.txt", O_RDONLY);
	sum = 0;
	while (1)
	{
		memset(&dict, 0, sizeof(dict));
		line = get_next_line(fd);
		if (!line)
			break ;
		len = strlen(line);
		line[len - 1] = 0;
		check_line(line, dict, len, 0);
		line = get_next_line(fd);
		if (!line)
			break ;
		len = strlen(line);
		line[len - 1] = 0;
		check_line(line, dict, len, 1);
		line = get_next_line(fd);
		if (!line)
			break ;
		len = strlen(line);
		line[len - 1] = 0;
		check_line(line, dict, len, 2);
		for (int i = 1; i <= 52; i++)
		{
			if (dict[i][0] == 3)
			{
				sum += i;
				break ;
			}
		}
	}
	fprintf(stderr, "SUM: %d\n", sum);
	return 0;
}

