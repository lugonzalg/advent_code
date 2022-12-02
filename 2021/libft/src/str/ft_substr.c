/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:14:03 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:14:06 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*n_str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	n_str = (char *)malloc(len * sizeof(char) + 1);
	if (!n_str)
		return (NULL);
	if (start > size)
	{
		*n_str = '\0';
		return (n_str);
	}
	while (len-- && s[start + i])
	{
		n_str[i] = s[start + i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
