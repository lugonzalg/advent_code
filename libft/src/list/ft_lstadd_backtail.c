/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_backtail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:32:47 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 13:33:44 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_backtail(t_list **lst, t_list *new, t_list **tail)
{
	t_list	*node;

	node = *lst;
	if (node)
	{
		node = ft_lstlast(node);
		node->next = new;
		(*tail) = new;
		new->next = NULL;
	}
	else
		(*lst) = new;
}
