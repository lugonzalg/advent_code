/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/06 21:05:50 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"

static char	**ft_occurrence(void)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open("input2", O_RDONLY);
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

static ssize_t	*ft_tab(char **tab, size_t *len)
{
	size_t	i;
	ssize_t	*fish;

	i = 0;
	while (tab[i])
		i++;
	*len = i;
	fish = (ssize_t *)ft_calloc(sizeof(ssize_t), i * 100000000);
	i = -1;
	while (tab[++i])
	{
		fish[i] = ft_atoi(tab[i]);
		free(tab[i]);
	}
	free(tab);
	return (fish);
}

static ssize_t	*ft_resize_list(ssize_t *list, size_t *len)
{
	size_t	i;
	//ssize_t	*n_list;

	i = -1;
	//n_list = (ssize_t *)ft_calloc(sizeof(ssize_t), (*len) + 1);
	//while (++i < *len)
	//	n_list[i] = list[i];
	list[(*len)] = 8;
	(*len)++;
	//free(list);
	return (list);
}

static void	ft_life(ssize_t *list, size_t len)
{
	size_t	days;
	size_t	i;

	days = 0;
	while (days < 256)
	{
		i = -1;
		while (++i < len)
			list[i]--;
		i = -1;
		while (++i < len)
		{
			if (list[i] == -1)
			{
				list = ft_resize_list(list, &len);
				list[i] = 6;
			}
		}
		days++;
	}
	i = -1;
	while (++i < len)
		printf("%zd,", len);
}

int	main(void)
{
	char	**tab;
	ssize_t	*list;
	size_t	len;

	tab = ft_occurrence();
	if (!tab)
		return (1);
	list = ft_tab(tab, &len);
	ft_life(list, len);
	return (0);
}
