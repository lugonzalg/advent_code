/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:19:41 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:19:42 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_TOOLS_H
# define NEW_TOOLS_H

# include <stdlib.h>
# include <stdint.h>

double	ft_atoi_double(const char *str);

int		ft_isdigit_double(int c);

double	scl_range(int size, int to_scl, double max_range, double min_range);

void	hex_to_str(uintptr_t n, char *hex);

void	ft_sort_arr(int **arr, int size);
int		*ft_duparr(int *arr, int size);
int		ft_findarr(int *arr, int size, int key);
int		ft_findarrb(int *arr, int size, int key);
int		ft_findaprox(int *arr, int size, int key);
int		ft_findaproxb(int *arr, int size, int key);

#endif
