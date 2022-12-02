# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 17:18:21 by lugonzal          #+#    #+#              #
# Updated: 2021/05/29 17:18:27 by lugonzal               ###   ########.fr     #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f
INC = -I ./inc
FILES = mem/ft_memset \
		mem/ft_bzero \
		mem/ft_memcpy \
		mem/ft_memccpy \
		mem/ft_memmove \
		mem/ft_memchr \
		mem/ft_memcmp \
		mem/ft_calloc \
		num/ft_atoi \
		num/ft_atoi_double \
		num/ft_itoa \
		num/ft_abs \
		str/ft_strmapi \
		str/ft_strlen \
		str/ft_strlcpy \
		str/ft_strlcat \
		str/ft_strchr \
		str/ft_strrchr \
		str/ft_strnstr \
		str/ft_strncmp \
		str/ft_strdup \
		str/ft_substr \
		str/ft_strjoin \
		str/ft_strtrim \
		str/ft_split_2 \
		str/ft_hex_to_str \
		is_checker/ft_isalpha \
		is_checker/ft_isdigit \
		is_checker/ft_isdigit_double \
		is_checker/ft_isalnum \
		is_checker/ft_isascii \
		is_checker/ft_isprint \
		to_some/ft_toupper \
		to_some/ft_tolower \
		fd/ft_putchar_fd \
		fd/ft_putstr_fd \
		fd/ft_putendl_fd \
		fd/ft_putnbr_fd \
		tools/scl_range \
		tools/ft_sort_arr \
		tools/ft_duparr \
		tools/ft_findarr \
		tools/ft_findarrb \
		tools/ft_findaprox \
		tools/ft_findaproxb \
		gnl/get_next_line \
		gnl/get_next_line_utils \
		gnl/get_next_line_bonus \
		gnl/get_next_line_utils_bonus 

FILES_B = list/ft_lstnew \
		  list/ft_lstadd_front \
		  list/ft_lstsize \
		  list/ft_lstlast \
		  list/ft_lstadd_back \
		  list/ft_lstadd_backtail \
		  list/ft_lstdelone \
		  list/ft_lstclear \
		  list/ft_lstiter \
		  list/ft_lstmap \
		  list/ft_lsttail_front \
		  list/ft_lst_int_array

SRCS_DIR = src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^
	ranlib $(NAME)

bonus: $(OBJS_B)
	$(AR) $(NAME) $^
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
