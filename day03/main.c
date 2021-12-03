/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/03 21:10:39 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"

static void	free_d2(char **data)
{
	size_t	i;

	i = -1;
	while (data[++i])
		free(data[i]);
	free(data);
}

static char	**ft_occurrence(void)
{
	int		fd;
	char	**info;
	size_t	i;

	i = 0;
	info = ft_calloc(sizeof(char *), 10001);
	fd = open("input5", O_RDONLY);
	while (1)
	{
		info[i] = get_next_line(fd);
		if (!info[i])
			break ;
		info[i][6] = 0;
		i++;
	}
	return (info);
}

static char **ft_resize(char **binary_info, char c, size_t pos, size_t *size, size_t old_size)
{
	char	**binary;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	binary = ft_calloc(sizeof(char *), size + 1);
	while (i < size)
	{
		while (++j < old_size)
		{
			if (binary_info[j][pos] == c)
				break ;
		}
		binary[i] = ft_strdup(binary_info[j]);
		i++;
	}
	(*size) = i;
	free_d2(binary_info);
	return (binary);
}

static char **ft_result(char **binary_info, size_t pos, size_t size)
{
	static int	binary[2] = {0};
	size_t		i;

	i = -1;
	while (++i < size)
	{
		if (binary_info[i][pos] - 48)
			binary[1]++;
		else
			binary[0]++;
	}
	if (binary[1] >= binary[0])
	{
		binary_info = ft_resize(binary_info, '1', pos, binary[1], size);
		if (size != 1)
			ft_result(binary_info, ++pos, 
	}
	else
		binary_info = ft_resize(binary_info, '0', pos, binary[0], size);
	return (binary_info);
}

int	main(void)
{
	char	**binary_info;

	binary_info = ft_occurrence();
	binary_info = ft_result(binary_info, 0, 12);
	printf("%s", binary_info[0]);
	printf("%s", binary_info[1]);
}
