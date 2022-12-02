/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/03 14:24:03 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"

static int ft_get_num(int fd, bool *status)
{
	int	num;
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		*status = false;
		return (0);
	}
	num = ft_atoi(line);
	free(line);
	return (num);
}

int	main(void)
{	
	int		fd;
	size_t	result;
	int		sum[5];
	bool	status;
	size_t	i;

	i = 0;
	status = 1;
	result = 0;
	fd = open("input_3", O_RDONLY);
	sum[0] = ft_get_num(fd, &status);
	sum[1] = ft_get_num(fd, &status);
	sum[2] = ft_get_num(fd, &status);
	sum[3] = sum[0] + sum[1] + sum[2];
	while (1)
	{
		sum[i] = ft_get_num(fd, &status);
		sum[4] = sum[0] + sum[1] + sum[2];
		if (!status)
			break ;
		if (sum[4] > sum[3])
			result++;
		sum[3] = sum[4];
		i++;
		if (i == 3)
			i = 0;
	}
	printf("%zu", result);
}
