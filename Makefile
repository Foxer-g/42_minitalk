CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAMESERV = server
NAMECLIENT = client
SRCDIRSERV = src/server/
SRCDIRCLIENT = src/client/
OBJDIRSERV = build/server/
OBJDIRCLIENT = build/client/
OBJDIR = build/
INCLUDE = -Iinclude -Ilibft/include
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

OBJSERV = main.o\

OBJCLIENT = main.o\


OBJSERVS = $(addprefix $(OBJDIRSERV), $(OBJSERV))
OBJCLIENTS = $(addprefix $(OBJDIRCLIENT), $(OBJCLIENT))

all: $(NAMESERV) $(NAMECLIENT) 

$(OBJDIRSERV):
	mkdir -p $@

$(OBJDIRCLIENT):
	mkdir -p $@

$(NAMESERV): $(OBJSERVS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJSERVS) $(LDFLAGS) $(LDLIBS) -o $@

$(NAMECLIENT): $(OBJCLIENTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJCLIENTS) $(LDFLAGS) $(LDLIBS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) -j

$(OBJDIRSERV)%.o: $(SRCDIRSERV)%.c | $(OBJDIRSERV)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIRCLIENT)%.o: $(SRCDIRCLIENT)%.c | $(OBJDIRCLIENT)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT_DIR) clean -j

fclean: clean
	rm -f $(NAMESERV)
	rm -f $(NAMECLIENT)
	make -C $(LIBFT_DIR) fclean -j

re: fclean
	make -C $(LIBFT_DIR) all -j
	make all

.PHONY: all clean fclean re
