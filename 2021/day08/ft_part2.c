/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:28:37 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/08 18:34:59 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "nums.h"
#include "get_next_line.h"

extern void	ft_free_d2(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static void	ft_get_nums(char *list[10], char *decrypt, size_t sz, size_t l_sz)
{
	char	**parse;
	size_t	i;

	parse = ft_split(decrypt, ' ');
	if (!parse)
		return ;
	i = -1;
	while (parse[++i])
	{
		if (ft_strlen(parse[i]) == sz)
		{
			list[l_sz] = ft_strdup(parse[i]);
			if (!list[l_sz])
				return ;
			ft_free_d2(parse);
			break ;
		}
	}

}

static void	ft_decrypt(size_t num_list[10], char *list[10], char *str)
{
	char	**tab;
	size_t	i;
	size_t	j;
	char	*trim;

	i = -1;
	tab = ft_split(str, ' ');
	if (!tab)
		return ;
	while (tab[++i])
	{
		j = -1;
		while (++j < 4)
		{
			if (ft_strlen(tab[i]) != ft_strlen(list[j]))
					continue ;
			trim = ft_strtrim(tab[i], list[j]);
			if (!ft_strlen(trim))
			{
				num_list[j]++;
				j = 4;
			}
			free(trim);
		}
		free(tab[i]);
	}

}

static void	ft_set_list(char *list[10], char *str)
{
	ft_get_nums(list, str, 2, 1);
	ft_get_nums(list, str, 3, 7);
	ft_get_nums(list, str, 4, 4);
	ft_get_nums(list, str, 8, 8);
	ft_get_9(list, str, 6, 9);
	ft_get_0(list, str, 6, 0);
	ft_get_6(list, str, 6, 6);
	ft_get_3(list, str, 5, 3);
	ft_get_5(list, str, 5, 5);
}

static int	*ft_part2(size_t num_list[10])
{
	char	*line;
	char	**decrypt;
	int		fd;
	char	*list[10];

	fd = open("input3", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		decrypt = ft_split(line, '|');
		if (!line)
			return (NULL);
		ft_set_list(list, decrypt[0]);
		free(decrypt[0]);
		decrypt[1][ft_strlen(decrypt[1]) - 1] = 0;
		ft_decrypt(num_list, list, decrypt[1]);
	}
}

int	main(void)
{
	size_t	num_list[10];
	size_t	sum;

	ft_memset(num_list, 0, sizeof(size_t) * 10);
	ft_part2(num_list);
	sum = num_list[0] + num_list[1] + num_list[2] + num_list[3];
	printf("SUM: %zd", sum);
	return (0);
}
