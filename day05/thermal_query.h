/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thermal_query.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:08:34 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/05 20:50:18 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THERMAL_QUERY_H
#define THERMAL_QUERY_H

#include <unistd.h>

extern int	ft_thermal_query(int **map, int **coord, int max);
extern void		ft_fill_x(int **map, int *coord, int x, int y);
extern void		ft_fill_y(int **map, int *coord, int x, int y);
extern void		ft_fill_diagonal_1(int **map, int *coord);
extern void		ft_fill_diagonal_2(int **map, int *coord, int x, int y);

#endif
