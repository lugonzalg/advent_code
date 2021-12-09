/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/09 16:41:58 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

#define ROW 7
#define FIX_ROW 6
#define COL 12
#define FIX_COL 11

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

static void	ft_basin_path(char tab[ROW][COL], size_t y, size_t x, size_t *sum, char init)
{
	if (tab[y][x] == '9')
		return ;
	if (x < FIX_COL && tab[y][x + 1] > tab[y][x] && tab[y][x] != 47)
	{
		(*sum)++;
		if (tab[y][x] != init)
			tab[y][x] = 47;
		ft_basin_path(tab, y, x + 1, sum, init);
	}
	if (x > 0 && tab[y][x - 1] > tab[y][x] && tab[y][x] != 47)
	{
		(*sum)++;
		if (tab[y][x] != init)
			tab[y][x] = 47;
		ft_basin_path(tab, y, x - 1, sum, init);
	}
	if (y < FIX_ROW && tab[y + 1][x] > tab[y][x] && tab[y][x] != 47)
	{
		(*sum)++;
		if (tab[y][x] != init)
			tab[y][x] = 47;
		ft_basin_path(tab, y + 1, x, sum, init);
	}
	if (y > 0 && tab[y - 1][x] > tab[y][x] && tab[y][x] != 47)
	{
		(*sum)++;
		if (tab[y][x] != init)
			tab[y][x] = 47;
		ft_basin_path(tab, y - 1, x, sum, init);
	}
}


static void	ft_check_basin(char tab[ROW][COL], size_t sum[3])
{
	size_t	y;
	size_t	x;
	size_t	k;
	size_t	sum_l;
	char	tmp_tab[ROW][COL];

	y = 0;
	(void)sum;
	while (++y <= FIX_ROW)
	{
		x = 0;
		while (++x <= FIX_COL)
		{
			if (tab[y][x] == '9')
				continue ;
			sum_l = 0;
			ft_memcpy(tmp_tab, tab, sizeof(char) * ROW * COL);
			ft_basin_path(tmp_tab, y, x, &sum_l, tmp_tab[y][x]);
			//ft_print_tab(tmp_tab);
			printf("Y: %zd X: %zd SUM: %zd VAL: %c\n", y, x, sum_l + 1, tab[y][x]);
			//printf("SUM: %zd\n", sum_l);
			k = -1;
			while (++k < 3)
			{
				if (sum_l > sum[k])
				{
					//ft_memcpy(tab, tmp_tab, sizeof(char) * ROW * COL);
					sum[k] = sum_l;
				}
			}
			//ft_print_tab(tmp_tab);
		}
	}
}

static void	ft_part2(char tab[ROW][COL])
{
	char	*line;
	int		fd;
	size_t	i;

	i = 1;
	fd = open("input2", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_memcpy(&tab[i][1], line, ft_strlen(line) - 1);
		i++;
	}
	ft_print_tab(tab);
}

int	main(void)
{
	char	tab[ROW][COL];
	size_t	sum[3];

	ft_memset(sum, 0, sizeof(size_t) * 3);
	ft_memset(tab, 58, sizeof(char) * ROW * COL);
	//ft_print_tab(tab);
	ft_part2(tab);
	ft_check_basin(tab, sum);
	printf("SUM1: %zd", sum[0]);
	printf("SUM2: %zd", sum[1]);
	printf("SUM3: %zd", sum[2]);
	return (0);
}
