/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bingo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:25:46 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/04 19:44:18 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINGO_H
#define BINGO_H

typedef struct s_node
{
	char			***board;
	struct s_node	*next;
	int				last_ref;
}	t_node;


extern int	ft_winner(t_node *head, char **list, size_t j);
extern size_t	ft_mark_board(t_node *head, char **list, size_t j);

#endif
