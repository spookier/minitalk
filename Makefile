# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acostin <acostin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:13:36 by acostin           #+#    #+#              #
#    Updated: 2023/05/01 18:13:41 by acostin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

# COLOR CODES
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
END_COLOR=\033[0m

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
	 @echo "$(COLOUR_GREEN)- BUILD SUCCESS\n$(END_COLOR)"

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)
	@echo "$(COLOUR_GREEN)- DELETED OBJECT FILES\n$(END_COLOR)"

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@echo "$(COLOUR_GREEN)- DELETED OBJECT FILES AND EXECUTABLES\n$(END_COLOR)"

re : fclean
	make all

.PHONY : all clean fclean re
