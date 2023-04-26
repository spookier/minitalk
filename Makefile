CC = cc
CFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client

INCS_DIR = ./incs
SRCS_DIR = ./srcs

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

SERVER_FILES = server.c \

CLIENT_FILES = client.c \


SERVER_SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(SERVER_FILES)))
SERVER_OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(SERVER_FILES)))

CLIENT_SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(CLIENT_FILES)))
CLIENT_OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(CLIENT_FILES)))

.c.o : $(SERVER_SRCS) $(CLIENT_SRCS) $(INCS_DIR)
		$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(LIBFT_NAME) $(SERVER) $(CLIENT)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)


fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)


re: fclean all


.PHONY: all clean fclean re