NAME = push_swap

SRCS = $(addprefix srcs/, \
	commands/push.c  commands/reverse_rotate.c commands/rotate.c commands/swap.c \
	push_swap.c error_handling.c  stack_init.c stack_utils.c \
	init_nodes_a.c init_nodes_b.c move_nodes.c sort_algorithms.c)

OBJS = $(SRCS:.c=.o)

# SRCS_B =
# OBJS_B = $(SRCS_B:.c=.o)

HEADER = -Iincludes

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# bonus: $(OBJS_B) $(LIBFT)
#	$(CC) $(OBJS_B) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT): FORCE
	make -C	$(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

# re_bonus: fclean bonus

FORCE:

.PHONY: all bonus clean fclean re re_bonus
