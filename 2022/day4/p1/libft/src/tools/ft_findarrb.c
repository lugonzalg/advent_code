/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findarrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:17:52 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:17:53 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_findarrb(int *arr, int size, int key)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (arr[size - i - 1] == key)
			return (i);
	}
	return (-1);
}
