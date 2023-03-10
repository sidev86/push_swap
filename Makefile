SRCFILES			= array_utils.c checkers.c chunks_utils.c \
				chunks_utils_2.c converters.c deallocate_utils.c \
				push_swap.c instructions.c sort_small.c sort_big.c \
				stack_a_utils.c stack_a_utils_2.c stack_b_utils.c \
				stack_utils.c populate_stack.c 

OBJECTS			= $(SRCFILES:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror


all: push_swap

push_swap: $(OBJECTS)
	gcc -o $@ $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) push_swap

re: fclean all

.PHONY: all clean fclean re
