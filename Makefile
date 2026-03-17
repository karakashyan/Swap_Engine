NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = push.c push_swap_utils.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
