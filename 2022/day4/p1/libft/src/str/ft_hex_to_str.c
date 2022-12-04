/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:11:06 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:11:09 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	hex_to_str(uintptr_t n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		hex_to_str(n / 16, hex);
		hex_to_str(n % 16, hex);
	}
	else if (n < 17)
	{
		if (n > 9)
			n += 39;
		while (hex[i] != '\0')
			i++;
		hex[i] = n + 48;
		hex[i + 1] = '\0';
	}
}
