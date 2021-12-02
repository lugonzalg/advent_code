/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/02 16:07:49 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"

static char	**ft_get_move(int fd)
{
	char	*line;
	char	**parsed;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	parsed = ft_split(line, ' ');
	free(line);
	if (!parsed)
		return (NULL);
	return (parsed);
}

int	main(void)
{	
	int		ho_pos;
	int		deph;
	int		fd;
	char	**parsed;

	ho_pos = 0;
	deph = 0;
	fd = open("input.txt", O_RDONLY);
	while (1)
	{
		parsed = ft_get_move(fd);
		if (!parsed)
			break ;
		if (!ft_strncmp(parsed[0], "forward", sizeof("forward")))
			ho_pos += ft_atoi(parsed[1]);
		else if (!ft_strncmp(parsed[0], "down", sizeof("down")))
			deph += ft_atoi(parsed[1]);
		else if (!ft_strncmp(parsed[0], "up", sizeof("up")))
			deph -= ft_atoi(parsed[1]);
	}
	printf("%d", deph * ho_pos);
}
