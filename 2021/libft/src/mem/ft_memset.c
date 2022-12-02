/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:09:08 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:09:12 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, long c, size_t len)
{
	int	i;

	i = 0;
	while (len--)
		((unsigned char *)str)[i++] = (unsigned char)c;
	return (str);
}
