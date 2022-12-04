/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:08:58 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:09:25 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*src2;
	unsigned char	*dst2;

	src2 = (unsigned char *) src;
	dst2 = (unsigned char *) dst;
	i = 0;
	if (!dst2 && !src2)
		return (NULL);
	while (len > i && src > dst)
	{
		dst2[i] = src2[i];
		i++;
	}
	while (len-- && src < dst)
	{
		dst2[len] = src2[len];
	}
	return (dst);
}
