# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfourne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/31 14:07:32 by jfourne           #+#    #+#              #
#    Updated: 2017/01/31 16:25:09 by jfourne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all, clean, fclean, re

SRC_PATH	=	src

SRC_NAME	=	main.c \
				ft_strjoin_and_clean.c \
				print_mode.c \
				param_t.c \
				param_l.c \
				redim.c \
				ft_lstfree.c \
				print_color.c \
				param_l_print.c \
				ft_parse_param.c \
				open_list.c \
				ft_print_ls.c \
				ft_opendir.c \
				ft_lstpush_back.c \
				ft_lst_sort.c \
				ft_lstreverse.c \
				ft_lstjoin.c

OBJ_PATH	=	obj

CPPFLAGS	=	-Iinclude

LDFLAGS		=	-Llibft

LDLIBS		=	-lft

NAME		=	ft_ls

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all:			$(NAME)

$(NAME):		$(OBJ)
				@cd Libft; make; cd ..
				$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
				@mkdir -p $(OBJ_PATH)
				$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
				rm -rf $(OBJ)
				@rm -rf $(OBJ_PATH)
				@cd Libft; make clean; cd ..

fclean:			clean
				rm -rf $(NAME)
				@cd Libft; make fclean; cd ..

re:				fclean all
				@cd Libft; make re; cd ..
