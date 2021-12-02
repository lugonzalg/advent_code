/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:08:12 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:08:16 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*srch;
	size_t			i;

	i = 0;
	srch = (unsigned char *) s;
	while (i < n)
	{
		if (srch[i] == (unsigned char)c)
			return (srch + i);
		i++;
	}
	return (NULL);
}
