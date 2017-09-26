# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfourne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:27:01 by jfourne           #+#    #+#              #
#    Updated: 2017/01/31 16:12:26 by jfourne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	:	all clean fclean re

SRC_PATH	=	src

SRC_NAME	=	ft_atoi.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_isneg.c \
				ft_ispos.c \
				ft_isspace.c \
				ft_lstback.c \
				ft_lstprint.c \
				ft_lstprintl.c \
				ft_strnjoin.c \

OBJ_PATH	=	obj

OBJ_NAME	=	$(SRC_NAME:.c=.o)

CPPFLAGS	=	-Iinclude

CFLAGS		=	-Wall -Werror -Wextra

NAME		=	libft.a

CC			=	gcc

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all	:			$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
				@mkdir -p $(OBJ_PATH)
				$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean	:
			rm -rf $(OBJ)
			@rm -rf $(OBJ_PATH)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
