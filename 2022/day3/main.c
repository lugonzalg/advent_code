#include <stdio.h>



int	main(void)
{
	char	*line;
	char	dict[52][2];
	size_t	len;
	int		fd;
	int		sum;

	fd = open("test_output.txt", O_RDONLY);
	//fd = open("output.txt", O_RDONLY);
	sum = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = strlen(line);
		memset(&dict, 0, sizeof(dict));
		check_line(line, &sum, dict, len);
	}
	fprintf(stderr, "SUM: %d\n", sum);
	return 0;
}

