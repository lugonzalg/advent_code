/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:11:55 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:11:59 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{	
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
