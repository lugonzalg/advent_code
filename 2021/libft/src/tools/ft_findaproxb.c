/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findaproxb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:15:23 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:17:30 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_findaproxb(int *arr, int size, int key)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (arr[size - i - 1] < key)
			return (i);
	}
	return (-1);
}
