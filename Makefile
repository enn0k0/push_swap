NAME = push_swap

CC = cc
##-------------use original---------------------
##CFLAGS = -Wall -Wextra -Werror
CFLAGS = 
##-------------use original---------------------

SRCS = push_swap.c ft_printf.c ft_helpers.c ft_libft_functions.c simple_algorithm.c stack_operations.c ft_medium_algorithm.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
##----------------REMOVE----------------
LIB = lib_push_swap.a
libclean: $(LIB) clean
##----------------REMOVE----------------

$(OBJS): push_swap.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

##----------------REMOVE----------------
$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)
##----------------REMOVE----------------

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libclean