/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:52:09 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/05 20:50:16 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thermal_query.h"
#include <stdlib.h>

extern void	ft_fill_diagonal_1(int **map, int *coord)
{
	int	y;
	int	x;
	int		m;

	x = (int)coord[2] - (int)coord[0];
	y = (int)coord[3] - (int)coord[1];
	m = y / x;
	if (coord[0] < coord[2])
		x = coord[0];
	else
		x = coord[2];
	while (x <= (int)coord[0] || x <= (int)coord[2])
	{
		y = (m * x - m * (int)coord[0]) + (int)coord[1];
		if (y < 0)
			y = -y;
		map[y][x]++;
		x++;
	}
}

extern void	ft_fill_y(int **map, int *coord, int x, int y)
{
	int	limit;

	if (coord[1] < coord[3])
	{
		y = coord[1];
		limit = coord[3];
	}
	else
	{
		y = coord[3];
		limit = coord[1];
	}
	while (y <= limit)
	{
		map[y][x]++;
		y++;
	}
}

extern void	ft_fill_x(int **map, int *coord, int x, int y)
{
	int	limit;

	if (coord[0] < coord[2])
	{
		x = coord[0];
		limit = coord[2];
	}
	else
	{
		x = coord[2];
		limit = coord[0];
	}
	while (x <= limit)
	{
		map[y][x]++;
		x++;
	}
}
