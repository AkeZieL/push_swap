NAME = push_swap

BONUS_NAME = checker



SRC = free.c init_stack.c push.c swap.c utils.c utils2.c \
      check_error.c ft_split.c reverse.c rotate.c

SRC_PUSH_SWAP = $(SRC) main.c trieur.c

SRC_CHECKER = $(SRC) checkers.c get_next_line_bonus.c ft_strjoin2.c ft_strchr.c



OBJS = $(SRC_PUSH_SWAP:.c=.o)

OBJS_BONUS = $(SRC_CHECKER:.c=.o)



CFLAGS = -Wall -Wextra -Werror



all: $(NAME)

$(NAME):	$(OBJS)
	gcc $(CFLAGS) $(SRC_PUSH_SWAP) -o $(NAME)

bonus:	$(OBJS_BONUS)
	gcc $(CFLAGS) $(SRC_CHECKER) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean:	clean
	rm -rf $(NAME) $(BONUS_NAME)

re:	fclean	all
