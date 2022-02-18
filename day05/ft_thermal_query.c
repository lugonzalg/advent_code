/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thermal_query.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:10:07 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/05 20:50:16 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "thermal_query.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"

static int	ft_diagonal(int *coord)
{
	int	y;
	int	x;

	x = (int)coord[2] - (int)coord[0];
	y = (int)coord[3] - (int)coord[1];
	if ((x % y))
		return (0);
	return (1);
}

static int	ft_coord_check(int *coord, int *x, int *y)
{
	if (coord[0] == coord[2])
	{
		*x = coord[0];
		return (1);
	}
	else if (coord[1] == coord[3])
	{
		*y = coord[1];
		return (1);
	}
	if (ft_diagonal(coord))
		return (2);
	return (0);
}

extern void	print_map(int **map, int max)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 10)
	{
		y = -1;
		while (++y < max)
			printf("%d", map[x][y]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

static int	ft_overlap(int **map, int max)
{
	int	i;
	int	j;
	int	overlap;

	overlap = 0;
	i = -1;
	while (++i < max)
	{
		j = -1;
		while (++j < max)
		{
			if (map[i][j] > 1)
				overlap++;
		}
	}
	return (overlap);
}

extern int	ft_thermal_query(int **map, int **coord, int max)
{
	int	i;
	int	x;
	int	y;
	int	option;

	i = -1;
	while (++i < 500)
	{
		x = 0;
		y = 0;
		option = ft_coord_check(coord[i], &x, &y);
		if (option == 1)
		{
			if (x)
				ft_fill_y(map, coord[i], x, y);
			else
				ft_fill_x(map, coord[i], x, y);
		}
		else if (option == 2)
			ft_fill_diagonal_1(map, coord[i]);
		else if (option == 3)
			ft_fill_diagonal_2(map, coord[i], x, y);
		printf("%d", i);
	}
	return (ft_overlap(map, max));
}
