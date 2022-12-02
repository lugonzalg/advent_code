/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bingo_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:52:50 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/04 20:34:57 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "bingo.h"
#include "../libft/inc/libft.h"

extern size_t	ft_mark_board(t_node *head, char **list, size_t j)
{
	size_t	i;
	size_t	k;
	bool	mark;

	while (head)
	{
		mark = false;
		i = -1;
		while (head && head->board[++i])
		{
			k = -1;
			while (head && head->board[i][++k])
			{
				if (ft_strncmp(head->board[i][k], list[j], 3))
					continue ;
				free(head->board[i][k]);
				head->board[i][k] = ft_strdup("x");
				head = head->next;
				i = 0;
				mark = true;
				break ;
			}
		}
		if (head && !mark)
		head = head->next;
	}
	return (j + 1);
}

static bool	ft_checkcol(char ***col)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (col[++j])
	{
		i = 0;
		while (col[j][i] && !ft_strncmp(col[j][i], "x", 2))
			i++;
		if (i == 5)
			return (true);
	}
	return (false);
}

static bool	ft_checkrow(t_node *head)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (head && head->board[i][j])
	{
		i = 0;
		while (head->board[i] && !ft_strncmp(head->board[i][j], "x", 2))
			i++;
		if (i == 5)
			return (true);
		j++;
	}
	return (false);
}

static int	ft_sumboard(t_node *head)
{
	size_t	i;
	size_t	j;
	int		sum;

	sum = 0;
	i = -1;
	while (head->board[++i])
	{
		j = -1;
		while (head->board[i][++j])
		{
			if (ft_strncmp(head->board[i][j], "x", 2))
				sum += ft_atoi(head->board[i][j]);
		}
	}
	return (sum);
}

extern void	print_table(char ***board)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
			printf("%s ", board[i][j]);
		printf("\n");
	}
}

extern int	ft_winner(t_node *head, char **list, size_t j)
{
	while (head)
	{
		if (!head->winner && (ft_checkcol(head->board) || ft_checkrow(head)))
		{
			g_n--;
			head->winner = true;
			if (!g_n)
				return (ft_sumboard(head) * ft_atoi(list[j]));
		}
		head = head->next;
	}
	return (0);
}
