/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:13:25 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:13:30 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*s3 != *s4)
			return (*s3 - *s4);
		if (!(*s3 || *s4))
			break ;
		s3++;
		s4++;
	}
	return (0);
}
