/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:13:06 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/08 18:41:59 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "nums.h"
#include "get_next_line.h"

extern void	ft_get_9(char *list[10], char *decrypt, size_t sz, size_t l_sz)
{
	char	**parse;
	size_t	i;
	char	*trim;

	parse = ft_split(decrypt, ' ');
	if (!parse)
		return ;
	i = -1;
	while (parse[++i])
	{
		trim = ft_strtrim(list[4], parse[i]);
		if (ft_strlen(parse[i]) == sz && !ft_strlen(trim))
		{
			free(trim);
			list[l_sz] = ft_strdup(parse[i]);
			if (!list[l_sz])
				return ;
			ft_free_d2(parse);
			break ;
		}
		free(trim);
	}
}

extern void	ft_get_0(char *list[10], char *decrypt, size_t sz, size_t l_sz)
{
	char	**parse;
	size_t	i;
	char	*trim[2];

	parse = ft_split(decrypt, ' ');
	if (!parse)
		return ;
	i = -1;
	while (parse[++i])
	{
		trim[0] = ft_strtrim(list[1], parse[i]);
		trim[1] = ft_strtrim(list[7], parse[i]);
		if (!ft_strlen(trim[0]) && !ft_strlen(trim[1]) && ft_strlen(parse[i]) == sz
				&& ft_strncmp(parse[i], list[9], 7))
		{
			free(trim[0]);
			free(trim[1]);
			list[l_sz] = ft_strdup(parse[i]);
			if (!list[l_sz])
				return ;
			ft_free_d2(parse);
			break ;
		}
		free(trim[0]);
		free(trim[1]);
	}
}

extern void	ft_get_6(char *list[10], char *decrypt, size_t sz, size_t l_sz)
{
	char	**parse;
	size_t	i;

	parse = ft_split(decrypt, ' ');
	if (!parse)
		return ;
	i = -1;
	while (parse[++i])
	{
		if (ft_strlen(parse[i]) == sz
				&& ft_strncmp(parse[i], list[7], 7)
				&& ft_strncmp(parse[i], list[0], 7)
				&& ft_strncmp(parse[i], list[9], 7))
		{
			list[l_sz] = ft_strdup(parse[i]);
			if (!list[l_sz])
				return ;
			ft_free_d2(parse);
			break ;
		}
	}
}

extern void	ft_get_3(char *list[10], char *decrypt, size_t sz, size_t l_sz)
{
	char	**parse;
	size_t	i;
	char	*trim;

	parse = ft_split(decrypt, ' ');
	if (!parse)
		return ;
	i = -1;
	while (parse[++i])
	{
		trim = ft_strtrim(list[1], parse[i]);
		if (ft_strlen(parse[i]) == sz
				&& !ft_strlen(trim))
		{
			free(trim);
			list[l_sz] = ft_strdup(parse[i]);
			if (!list[l_sz])
				return ;
			ft_free_d2(parse);
			break ;
		}
		free(trim);
	}
}

extern void	ft_get_5(char *list[10], char *decrypt, size_t sz, size_t l_sz)
{
	char	**parse;
	size_t	i;
	char	*trim;

	(void)sz;
	parse = ft_split(decrypt, ' ');
	if (!parse)
		return ;
	i = -1;
	while (parse[++i])
	{
		trim = ft_strtrim(list[9], parse[i]);
		if (ft_strncmp(parse[i], list[9], 7)
				&& ft_strlen(trim) == 1)
		{
			free(trim);
			list[l_sz] = ft_strdup(parse[i]);
			if (!list[l_sz])
				return ;
			ft_free_d2(parse);
			break ;
		}
		free(trim);
	}
}
