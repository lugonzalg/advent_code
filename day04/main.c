/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:56:20 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/04 20:34:56 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"
#include "bingo.h"

static void	ft_lst_addback(t_node **head, t_node *node)
{
	t_node	*tmp;

	if (!(*head))
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

static void	ft_fill_node(t_node *node, int fd)
{
	size_t	i;
	char	*nl;
	char	*line;

	i = -1;
	node->board = ft_calloc(sizeof(char **), 7);
	while (++i < 5)
	{
		line = get_next_line(fd);
		nl = ft_strchr(line, 10);
		*nl = 0;
		node->board[i] = ft_split(line, ' ');
		free(line);
	}
}

static t_node	*ft_occurrence(char **num_list)
{
	char	*line;
	int		fd;
	t_node	*node;
	t_node	*head;

	fd = open("input1", O_RDONLY);
	(*num_list) = get_next_line(fd);
	head = NULL;
	while (1)
	{
		line =  get_next_line(fd);
		if (!line)
			break ;
		g_n++;
		node = ft_calloc(sizeof(t_node), 1);
		ft_fill_node(node, fd);
		ft_lst_addback(&head, node);
	}
	return (head);
}

static int	ft_bingo_game(t_node *head, char *num_list)
{
	char	**list;
	int		winner;
	size_t	j;

	j = 0;
	winner = 0;
	list = ft_split(num_list, ',');
	free(num_list);
	while (1)
	{
		j = ft_mark_board(head, list, j);
		if (j > 4)
			winner = ft_winner(head, list, j - 1);
		if (winner)
			break ;
	}
	return (winner);
}

int	main(void)
{
	char	*num_list;
	t_node	*head;
	int		winner;

	g_n = 0;
	head = ft_occurrence(&num_list);
	winner = ft_bingo_game(head, num_list);
	printf("%d", winner);
}
