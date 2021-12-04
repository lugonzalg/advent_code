/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bingo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:25:46 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/04 20:34:57 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINGO_H
#define BINGO_H

#include <stdbool.h>

typedef struct s_node
{
	char			***board;
	struct s_node	*next;
	bool			winner;
}	t_node;

int	g_n;


extern int		ft_winner(t_node *head, char **list, size_t j);
extern size_t	ft_mark_board(t_node *head, char **list, size_t j);
extern void	print_table(char ***board);

#endif
