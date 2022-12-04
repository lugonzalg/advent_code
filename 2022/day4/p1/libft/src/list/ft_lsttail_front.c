/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:06:59 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:07:02 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsttail_front(t_list **lst, t_list **tail)
{
	t_list	*tmp;
	t_list	*head_ref;

	head_ref = (*lst);
	while ((*lst)->next->next)
		(*lst) = (*lst)->next;
	tmp = (*lst)->next;
	tmp->next = head_ref;
	(*lst)->next = NULL;
	(*tail) = (*lst);
	(*lst) = tmp;
}
