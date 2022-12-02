PART_1	= day091
PART_2	= day092

LIB		= -L /Users/lugonzal/Cursus_42/advent -lft
INC		= -I /Users/lugonzal/Cursus_42/advent/libft/inc
CC		= clang
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3

FILES_1	= ft_part1 \

OBJS_1 	= $(addsuffix .o, $(FILES_1))
SRCS_1 	= $(addsuffix .c, $(FILES_1))

FILES_2	= ft_part2 \

OBJS_2 	= $(addsuffix .o, $(FILES_2))
SRCS_2 	= $(addsuffix .c, $(FILES_2))

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@

all:

1: $(PART_1)
2: $(PART_2)

$(PART_1): $(OBJS_1)
	$(CC) $(CFLAGS) -o $(PART_1) $(OBJS_1) $(LIB)

$(PART_2): $(OBJS_2)
	$(CC) $(CFLAGS) -o $(PART_2) $(OBJS_2) $(LIB)

re: fclean all

clean:
	$(RM) $(OBJS_1)
	$(RM) $(OBJS_2)

fclean: clean
	$(RM) $(PART_1)
	$(RM) $(PART_2)

.PHONY: 1 2 clean fclean re
