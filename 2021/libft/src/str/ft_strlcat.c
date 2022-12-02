/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:12:14 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:12:19 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	j = 0;
	i = 0;
	while (i < dstsize && dst[i])
		i++;
	while (dstsize != 0 && i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize != 0 && dstsize > dst_size)
		dst[i] = '\0';
	return (i - j + ft_strlen(src));
}
