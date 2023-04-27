CC = cc
# CFLAGS = -Wall -Werror -Wextra
# CFLAGS =

SERVER_NAME = server
CLIENT_NAME = client

INCS_DIR = ./incs
SRCS_DIR = ./srcs/

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

SERVER_FILES = $(SRCS_DIR)server.c \

CLIENT_FILES = $(SRCS_DIR)client.c \

SERVER_OBJS = $(SERVER_FILES:.c=.o)
CLIENT_OBJS = $(CLIENT_FILES:.c=.o)

.c.o: $(SERVER_FILES) $(CLIENT_FILES) $(INCS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)

all: $(LIBFT_NAME) $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

# Clean all object files created
clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

# Clean all object files + the library created
fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

#Fclean then build all
re : fclean
	make all

.PHONY : all clean fclean re