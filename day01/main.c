/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/02 14:36:14 by lugonzal         ###   ########.fr       */
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
	int		num[2];
	bool	status;

	status = 1;
	result = 0;
	fd = open("input.txt", O_RDONLY);
	num[0] = ft_get_num(fd, &status);
	while (1)
	{
		num[1] = ft_get_num(fd, &status);
		if (!status)
			break ;
		if (num[1] > num[0])
			result++;
		num[0] = num[1];
	}
	printf("%zu", result);
}
