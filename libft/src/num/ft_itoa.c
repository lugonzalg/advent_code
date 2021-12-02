/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:10:41 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:10:44 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_power_num(unsigned int num)
{
	int	i;

	i = 0;
	while (num > 9)
	{	
		num /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_putnbr(unsigned int num, char *str)
{
	unsigned int	size;

	size = ft_power_num(num) - 1;
	str[size + 1] = '\0';
	if (num == 0)
		str[size] = num % 10 + '0';
	while (num > 0)
	{		
		str[size] = num % 10 + '0';
		num /= 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				negativo;
	unsigned int	num;

	negativo = 0;
	if (n < 0)
	{
		negativo = 1;
		num = (unsigned int) -n;
	}
	else
		num = (unsigned int) n;
	str = (char *)malloc((ft_power_num(num) + negativo) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (negativo)
	{	
		*str = '-';
		str++;
	}
	return (ft_putnbr(num, str) - negativo);
}
