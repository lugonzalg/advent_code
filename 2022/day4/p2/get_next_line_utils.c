/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:27:21 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 13:27:26 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int	len_c(char	*str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_nl(char	*str, char c)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == c)
			return (str + i);
	}
	return (NULL);
}

char	*strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*n_str;

	i = -1;
	j = -1;
	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	n_str = malloc(len_c(str1, 0) + len_c(str2, 0) + 1);
	if (!n_str)
		return (NULL);
	while (str1[++i])
		n_str[i] = str1[i];
	while (str2[++j])
		n_str[i + j] = str2[j];
	n_str[j + i] = '\0';
	free(str1);
	return (n_str);
}

char	*cutstr(char *str, int start, int len, int on)
{
	int		i;
	char	*n_str;

	i = 0;
	if (!ft_nl(str, '\n') && on)
	{
		free(str);
		return (NULL);
	}
	n_str = malloc(len + 1);
	if (!n_str)
		return (NULL);
	while (i < len && str[start + i])
	{
		n_str[i] = str[start + i];
		i++;
	}
	n_str[i] = '\0';
	if (on)
		free(str);
	return (n_str);
}

char	*ret_val(int size, char *line)
{	
	if (!size && !len_c(line, 0))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
