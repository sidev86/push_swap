SRCFILES			=	push_swap.c instructions.c sort_small.c

OBJECTS			= $(SRCFILES:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= push_swap.a

all:			$(NAME)

$(NAME):		$(OBJECTS)
				ar rcs $(NAME) $(OBJECTS)

clean:
				$(RM) $(OBJECTS) $(BOBJECTS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
