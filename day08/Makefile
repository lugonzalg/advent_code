NAME	= day08

LIB		= -L /Users/lugonzal/Cursus_42/advent -lft
INC		= -I /Users/lugonzal/Cursus_42/advent/libft/inc
CC		= clang
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3
FILES	= ft_part2 \
		  ft_get_num

OBJS 	= $(addsuffix .o, $(FILES))
SRCS 	= $(addsuffix .c, $(FILES))

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
