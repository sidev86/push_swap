SRCFILES			= array_utils.c stack_checkers.c chunks_utils.c \
				chunks_utils_2.c converters.c deallocate_utils.c \
				push_swap.c instructions.c sort_small.c sort_big.c \
				stack_a_utils.c stack_a_utils_2.c stack_b_utils.c \
				stack_utils.c populate_stack.c 
BFILES				= checker.c instructions.c stack_checkers.c populate_stack.c \
				deallocate_utils.c get_next_line.c get_next_line_utils.c converters.c
				

OBJECTS			= $(SRCFILES:.c=.o)
BOBJECTS		= $(BFILES:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror


all: push_swap

bonus: push_swap checker

push_swap: $(OBJECTS)
	gcc -o $@ $(OBJECTS)

checker: $(BOBJECTS)
	gcc -o $@ $(BOBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJECTS) $(BOBJECTS)

fclean: clean
	$(RM) push_swap checker

re: fclean all

.PHONY: all bonus clean fclean re
