NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

DIR = srcs
SRCS_RAW = main.c utils.c
SRCS = $(addprefix $(DIR)/,$(SRCS_RAW)) \

OBJS = $(SRCS:c=o)
INCLUDES = -I./includes -I./libft

LIBFT = libft.a

all: $(NAME)
$(NAME): libftcompile $(OBJS)
	$(CC) $(OBJS) $(DEBUG) -Llibft -l:libft.a -o $(NAME)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean libftclean
	rm $(NAME) -f
re: fclean all
libftcompile:
	$(MAKE) -C libft
libftclean:
	$(MAKE) fclean -C libft

%.o: %.c def.h
	$(CC) -c $< -o $@ $(DEBUG) $(CFLAGS) $(INCLUDES)