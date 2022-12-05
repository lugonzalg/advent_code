NAME	= auto

CC		= clang++
CFLAGS	= -g3 -Wall -Werror -Wextra
SNTZ	= -fsanitize=address

INC		= -I .
LIB		= -L .

FILES	= main

SRC 	= $(addsuffix .cpp, $(FILES))
OBJ 	= $(addsuffix .o, $(FILES))

.cpp.o:
	$(CC) $(CFLAGS) $(SNTZ) -o $@ -c $^

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SNTZ) -o $(NAME) $(OBJ)

all: $(NAME)

run: all
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
