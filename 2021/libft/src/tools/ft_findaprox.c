/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findaprox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:15:08 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:15:09 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_findaprox(int *arr, int size, int key)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (arr[i] < key)
			return (i);
	}
	return (-1);
}
