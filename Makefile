SRCFILES			= array_utils.c checkers.c chunks_utils.c \
				chunks_utils_2.c converters.c deallocate_utils.c \
				push_swap.c instructions.c sort_small.c sort_big.c \
				stack_a_utils.c stack_a_utils_2.c stack_b_utils.c \
				stack_utils.c populate_stack.c

OBJECTS			= $(SRCFILES:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJECTS)
				gcc -o $@ $(OBJECTS)

clean:
				$(RM) $(OBJECTS) $(BOBJECTS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
