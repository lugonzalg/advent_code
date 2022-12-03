/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:18:53 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/01 19:36:49 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
int		len_c(char	*str, char c);
char	*ft_nl(char	*str, char c);
char	*strjoin(char *str1, char *str2);
char	*cutstr(char *str, int start, int len, int on);
char	*ret_val(int size, char *line);

#endif
