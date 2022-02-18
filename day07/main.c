/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/07 19:11:58 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

static char	**ft_occurrence(void)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open("input1", O_RDONLY);
	if (fd == -1)
		return (NULL);
	line =  get_next_line(fd);
	if (!line)
		return (NULL);
	tab = ft_split(line, ',');
	if (!tab)
		return (NULL);
	free(line);
	return (tab);
}

static size_t	*ft_tab(char **tab, size_t *sz)
{
	size_t	i;
	size_t	*arr;

	i = 0;
	while (tab[i])
		i++;
	*sz = i;
	arr = ft_calloc(sizeof(size_t), i);
	i = -1;
	while (tab[++i])
	{
		arr[i] = ft_atoi(tab[i]);
		free(tab[i]);
	}
	free(tab);
	return (arr);
}

static int	ft_find_ave(size_t *arr, size_t sz)
{
	size_t 	sum;
	size_t	i;
	float	av;

	i = -1;
	sum = 0;
	while (++i < sz)
		sum += arr[i];
	av = (float)sum / (float)sz;
	if (av - (int)av > 0.49)
		return ((int)av + 1);
	else
		return (av);
}

static void	ft_outcome(size_t sz, size_t *arr)
{
	size_t	sum[2];
	size_t	i;
	size_t	j;
	int		moves;
	int		average;

	average = ft_find_ave(arr, sz);
	printf("FUEL: %d", average);
	ft_memset(sum, 0, sizeof(size_t) * 2);
	j = average - 4;
	sum[1] = 2147483647;
	while (++j < average + 4)
	{
		i = -1;
		sum[0] = 0;
		while (++i < sz)
		{
			moves = arr[i] - j;
			if (moves < 0)
				moves = -moves;
			if (moves % 2)
				sum[0] += ((moves + 1) * (moves/2)) + ( moves/2 + 1);
			else
				sum[0] += (1 + moves) * (moves / 2);
		}
		if (sum[0] < sum[1])
			sum[1] = sum[0];
	}
	printf("FUEL: %zd\n", sum[1]);
}
/* sort all numbers, get median */
static void	ft_part1(size_t *arr, size_t sz)
{
	size_t	i;
	size_t	j;
	size_t	swap;

	i = -1;
	while (++i < sz)
	{
		j = -1;
		while (++j < sz)
		{
			if (arr[i] > arr[j])
			{
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
		}
	}
	ft_outcome(sz, arr);
}

int	main(void)
{
	char	**tab;
	size_t	*list;
	size_t	sz;

	tab = ft_occurrence();
	if (!tab)
		return (1);
	list = ft_tab(tab, &sz);
	ft_part1(list, sz);
	return (0);
}
