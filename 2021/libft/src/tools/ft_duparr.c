/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duparr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:14:55 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:14:57 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_duparr(int *arr, int size)
{
	int	i;
	int	*n_arr;

	i = -1;
	n_arr = (int *)malloc(sizeof(int) * size);
	if (!n_arr)
		return (NULL);
	while (++i < size)
		n_arr[i] = arr[i];
	return (n_arr);
}
