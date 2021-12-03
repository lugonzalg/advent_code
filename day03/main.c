/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/03 16:32:59 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"

static void	ft_check_binary(int bit_rate[12][2], char *line)
{
	size_t	j;

	j = 0;	
	while (line[j] && line[j] != 10)
	{
		line[j] -= 48;
		if (line[j])
			bit_rate[j][1]++;
		else
			bit_rate[j][0]++;
		j++;
	}
}

static char	**ft_binary_result(int bit_rate[12][2])
{
	static char	*epsilon[2];
	size_t		j;

	j = -1;
	epsilon[0] = ft_calloc(sizeof(char), 13);
	epsilon[1] = ft_calloc(sizeof(char), 13);
	while (++j < 12)
	{
		if (bit_rate[j][1] > bit_rate[j][0])
		{
			epsilon[0][j] = '1';	
			epsilon[1][j] = '0';	
		}
		else
		{
			epsilon[0][j] = '0';	
			epsilon[1][j] = '1';	
		}
	}
	return (epsilon);
}

int	main(void)
{	
	char		*line;
	int			fd;
	static int	bit_rate[12][2];
	char		**result;

	fd = open("1", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_check_binary(bit_rate, line);
		free(line);
	}
	result = ft_binary_result(bit_rate);
	printf("RESULT_1: %s\n", result[0]);
	printf("RESULT_2: %s", result[1]);
	free(result[0]);
	free(result[1]);
}
