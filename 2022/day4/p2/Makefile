NAME	= auto

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3
SNTZ	= -fsanitize=address

INC		= -I ./libft/inc
LIB		= -L libft -lft

FILES	= main \
		  get_next_line \
		  get_next_line_utils

SRC 	= $(addsuffix .c, $(FILES))
OBJ 	= $(addsuffix .o, $(FILES))

.c.o:
	$(CC) $(CFLAGS) $(INC) $(SNTZ) -o $@ -c $^

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(SNTZ) -o $(NAME) $(OBJ) $(LIB)

all: $(NAME)

run: all
	./$(NAME)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
