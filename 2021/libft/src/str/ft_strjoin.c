/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:12:38 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:12:41 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	int		size_s1;
	int		size_s2;
	int		i;

	if ((!s1 || !s2))
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	i = -1;
	n_str = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (n_str == NULL)
		return (NULL);
	while (*s1)
		n_str[++i] = *s1++;
	i++;
	while (*s2)
		n_str[i++] = *s2++;
	n_str[i] = '\0';
	return (n_str);
}
