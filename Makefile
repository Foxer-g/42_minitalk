CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = server\
	client\
SRCDIR = src/
OBJDIRSERV = build/server
OBJDIRCLIENT = build/client
INCLUDE = -Iinclude -Ilibft/include
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

OBJSERV = main.o\


OBJCLIENT = main.o\


OBJSERVS = $(addprefix $(OBJDIRSERV), $(OBJSERV))
OBJCLIENTS = $(addprefix $(OBJDIRCLIENT), $(OBJCLIENT))

all: $(NAME)

$(OBJDIRSER):
	mkdir -p $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) -j

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT_DIR) clean -j

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean -j

re: fclean
	make -C $(LIBFT_DIR) all -j
	make all

.PHONY: all clean fclean re
