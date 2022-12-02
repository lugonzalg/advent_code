/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/05 20:50:15 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "thermal_query.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"

static int	*ft_coord(char *line, int *max)
{
	int	*coord;
	char	**tab;
	int	i;

	coord = (int *)ft_calloc(sizeof(int),  5);
	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]))
				line[i] = ',';
	}
	tab = ft_split(line, ',');
	free(line);
	i = -1;
	while (tab[++i])
	{
		coord[i] = ft_atoi(tab[i]);
		if (coord[i] > (*max))
			(*max) = coord[i];
		free(tab[i]);
	}
	free(tab);
	return (coord);
}

static int	**ft_occurrence(int *max)
{
	char	*line;
	int		fd;
	int	**coord;
	int	i;

	coord = (int **)ft_calloc(sizeof(int *), 501);
	fd = open("input1", O_RDONLY);
	i = -1;
	while (1)
	{
		line =  get_next_line(fd);
		if (!line)
			break ;
		coord[++i] = ft_coord(line, max);
	}
	return (coord);
}

static int	**ft_create_map(int	max)
{
	int	**map;
	int	i;

	map = (int **)ft_calloc(sizeof(int *), max + 2);
	i = -1;
	while (++i < max + 2)
		map[i] = (int *)ft_calloc(sizeof(int), max + 2);
	return (map);
}

int	main(void)
{
	int		**coord;
	int	**map;
	int	max;

	max = 0;
	coord = ft_occurrence(&max);
	map = ft_create_map(max);
	printf("\nOVERLAP-> %d\n", ft_thermal_query(map, coord, max + 1));
	return (0);
}
