/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/10 20:13:21 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

extern void	ft_free_d2(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static int	ft_find_start(char *line, size_t i, size_t j, char start[4])
{
	size_t	k;
	size_t	tmp_i;

	tmp_i = i;
	while (i > 0)
	{
		k = -1;
		while (++k < 4)
		{
			if (line[i] == start[k])
			{
				line[tmp_i] = 'x';
				line[i] = 'x';
				return (0);
			}
			else if (k != j && line[i] == start[k])
				return (1);
		}
		i--;
	}
	return (0);
}

static char	ft_check_str(char *line, char end[4], char start[4])
{
	size_t	i;
	size_t	j;

	i = -1;
	while (line[++i])
	{
		j = -1;
		while (++j < 4)
		{
			if (line[i] == end[j] && ft_find_start(line, i, j, start))
				break ;
		}
		if (j == 4)
	}
	return (line[i]);
}

static size_t ft_error_case(char c)
{
	if (c == ')')
		return (3);
	else if (c == ']')
		return (57);
	else if (c == '}')
		return (1197);
	else
		return (25137);
}

static void	ft_part1(size_t	*sum, char end[4], char start[4])
{
	char	*line;
	int		fd;
	char	error;

	fd = open("input1", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		error = ft_check_str(line, end, start);
		if (error)
			*sum += ft_error_case(error);
	}
}

int	main(void)
{
	size_t	sum;
	char	end[4] = {')', ']', '}', '>'};
	char	start[4] = {'(', '[', '{', '<'};
	sum = 0;
	ft_part1(&sum, end, start);
	return (0);
}
