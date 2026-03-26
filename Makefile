NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c push.c parse.c utils.c swap.c rotate.c reverse.c sort.c utils2.c bench.c
BONUS_SRCS = checker_bonus.c push.c parse.c swap.c rotate.c reverse.c sort.c utils.c utils2.c bench.c Libft/get_next_line.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o checker

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
