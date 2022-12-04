/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_int_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:32:06 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 13:33:58 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

int	*ft_lst_int(t_list *head, int *size)
{
	int	*new_list;
	int	i;

	new_list = (int *)malloc(ft_lstsize(head) * sizeof(int));
	i = 0;
	while (head)
	{
		new_list[i] = (intptr_t)head->content;
		head = head->next;
		i++;
	}
	(*size) = i;
	return (new_list);
}
