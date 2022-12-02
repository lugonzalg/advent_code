/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/04 15:01:19 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"

static char	**ft_occurrence(void)
{
	int			fd;
	char	**info;
	size_t		i;

	i = 0;
	info = ft_calloc(sizeof(char *), 10001);
	fd = open("input4", O_RDONLY);
	while (1)
	{
		info[i] = get_next_line(fd);
		if (!info[i])
			break ;
		info[i][12] = 0;
		i++;
	}
	return (info);
}

static void	ft_fill_binary(char *result, size_t binary[2], size_t pos, bool on)
{
	if (on)
	{
		if (binary[1] >= binary[0])
			result[pos] = '1';
		else
			result[pos] = '0';
	}
	else
	{
		if (binary[0] <= binary[1])
			result[pos] = '0';
		else
			result[pos] = '1';
	}
}

static char *ft_result(char **binary_info, size_t pos, char *result, bool on)
{
	size_t	i;
	size_t	res_size;
	size_t	binary[2];
	size_t	j[2];

	ft_memset(j, 0, sizeof(size_t) * 2);
	ft_memset(binary, 0, sizeof(size_t) * 2);
	res_size = ft_strlen(result);
	i = -1;
	while (binary_info[++i])
	{
		if (!ft_strncmp(result, binary_info[i], res_size))
		{
			j[0]++;
			j[1] = i;
			if (binary_info[i][pos] - 48)
				binary[1]++;
			else
				binary[0]++;
		}
	}
	if (j[0] == 1)
		return (ft_memcpy(result, binary_info[j[1]], 13));
	ft_fill_binary(result, binary, pos, on);
	if (pos < 11)
		ft_result(binary_info, ++pos, result, on);
	return (result);
}

int	main(void)
{
	char	*result[2];

	result[0] = ft_calloc(sizeof(char), 13);
	result[1] = ft_calloc(sizeof(char), 13);
	result[0] = ft_result(ft_occurrence(), 0, result[0], true);
	result[1] = ft_result(ft_occurrence(), 0, result[1], false);
	printf("%s\n", result[0]);
	printf("%s", result[1]);
}
