/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:10:04 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:10:33 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_tools.h"

static int	sign_checker(const char *str)
{
	int	sign;

	sign = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign += 2;
		else if (*str == '+')
			sign++;
	}
	if (sign > 2)
		return (0);
	else if (sign == 1)
		sign *= -1;
	return (sign);
}

double	ft_atoi_double(const char *str)
{
	double	out;
	int		neg_decimal[2];

	neg_decimal[0] = 9;
	neg_decimal[1] = sign_checker(str);
	out = 0.0;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	while ((*str >= 48 && *str < 58) || *str == '.')
	{
		if (*str == '.' && neg_decimal[0]++)
			str++;
		if (neg_decimal[0] < 10 && ft_isdigit_double(*str))
			out = out * 10 + (*str - '0');
		else if (neg_decimal[0] > 9 && ft_isdigit_double(*str))
		{
			out = out + ((double)(*str - '0') / neg_decimal[0]);
			neg_decimal[0] *= 10;
		}
		str++;
	}
	return (out * neg_decimal[1]);
}
