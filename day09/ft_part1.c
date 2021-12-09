/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/09 13:34:19 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

#define ROW 102
#define COL 102

extern void	ft_free_d2(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static void	ft_print_tab(char tab[ROW][COL])
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < ROW)
	{
		j = -1;
		printf("%zu ", i);
		while (++j < COL)
			printf("%c", tab[i][j]);
		printf("\n");
	}
}

static void	ft_check_point(char tab[ROW][COL])
{
	size_t	y;
	size_t	x;
	size_t	sum;
	char	pos;

	sum = 0;
	y = 0;
	while (++y < ROW)
	{
		x = 0;
		while (++x < COL)
		{
			pos = tab[y][x];
			if (pos < tab[y - 1][x] && pos < tab[y + 1][x]
				&& pos < tab[y][x + 1] && pos < tab[y][x - 1])
				sum += pos - 47;
		}
	}
	printf("%zd", sum);
}

static void	ft_part1(char tab[ROW][COL])
{
	char	*line;
	int		fd;
	size_t	i;

	i = 1;
	fd = open("input1", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_memcpy(&tab[i][1], line, ft_strlen(line) - 1);
		i++;
	}
	ft_check_point(tab);
	printf("HEEEEEEEEY");
	printf("\n");
	printf("\n");
	printf("\n");
	ft_print_tab(tab);
}

int	main(void)
{
	char	tab[ROW][COL];
	//size_t	sum;

	ft_memset(tab, 58, sizeof(char) * ROW * COL);
	ft_print_tab(tab);
	ft_part1(tab);
	return (0);
}
