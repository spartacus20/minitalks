CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = server
NAMEC = client
INCLUDES = include
OBJS_DIR = obj/
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(patsubst %,$(OBJS_DIR)%,$(SRCS_SERVER:.c=.o))
OBJS_CLIENT = $(patsubst %,$(OBJS_DIR)%,$(SRCS_CLIENT:.c=.o))
LIBFT = libft
GREEN = \033[0;92m

all: $(LIBFT)/libft.a $(NAME) $(NAMEC)

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(NAME): $(OBJS_SERVER)
	@${CC} ${CFLAGS} $(OBJS_SERVER) -I $(INCLUDES) ./libft/libft.a -o $(NAME)
	@echo "$(GREEN) $(NAME) has been created."

$(NAMEC): $(OBJS_CLIENT)
	@${CC} ${CFLAGS} $(OBJS_CLIENT) -I $(INCLUDES) ./libft/libft.a -o $(NAMEC)
	@echo "$(GREEN) $(NAMEC) has been created."

$(OBJS_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME) $(NAMEC)
	rm -f libft.a
	rm -rf $(OBJS_DIR)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
