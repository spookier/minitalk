# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acostin <acostin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 14:13:22 by acostin           #+#    #+#              #
#    Updated: 2022/12/15 18:02:38 by acostin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Mandatory files
FILES = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \


# Bonus files
FILES_BONUS = 	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

# Transform .c files into .o
OBJ_FILES = $(FILES:.c=.o)
OBJ_BONUS = $(FILES_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) -c $(FILES)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)


bonus :
	$(CC) $(CFLAGS) -c $(FILES_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)
	

# Clean all object files created
clean : 
	rm -rf $(OBJ_FILES)
	rm -rf $(OBJ_BONUS)

# Clean all object files + the library created
fclean : clean
	rm -rf $(NAME)

# Delete everything then rebuild
re : fclean
	make all

.PHONY : all clean fclean re bonus