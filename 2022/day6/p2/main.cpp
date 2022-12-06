#include <fstream>
#include <iostream>

#include <string.h>

static int	process_line(char buffer[1000])
{
	char	chr_map[255];
	int		ctx;
	size_t	len;
	size_t	mark;

	len = strlen(buffer);
	for (size_t	i = 0; i < len; i++)
	{
		memset(chr_map, 0, 255);
		mark = 0;
		for (size_t	j = i; j < len; j++)
		{
			ctx = buffer[j];
			if (chr_map[ctx])
				break ;
			chr_map[ctx] = 1;
			mark++;
			if (mark == 14)
				return (j + 1);
		}
	}
	return (0);
}

int	main(void)
{
	//std::ifstream	in("test_output.txt");
	std::ifstream	in("output.txt");
	char			buffer[10000];
	int				sum;

	sum = 0;
	while (1)
	{
		memset(buffer, 0, 10000);
		in.getline(buffer, 10000);
		sum += process_line(buffer);
		if (in.peek() == EOF)
			break ;
	}
	std::cout << sum;
	return(0);
}
