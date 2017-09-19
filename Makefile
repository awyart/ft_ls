# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awyart <awyart@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 22:10:59 by awyart            #+#    #+#              #
#    Updated: 2017/09/19 13:26:25 by awyart           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_ls
FLAGS = -Werror -Wall -Wextra

SRC1 = main.c\

SRC2 = create.c \
		read.c \
		norec.c

SRC3 = get_content.c \
		exit.c \
		max.c

SRC4 = draw.c \
		draw2.c \

SRC5 = get_option.c 

SRC6 = ft_d.c \
		ft_f.c \
		ft_sm.c \
		ft_t.c \
		ft_u.c \
		ft_um.c

SRC7 = ft_strchr.c \
		ft_strcmp.c  \
		ft_strjoin.c \
		ft_strcpy.c \

SRC = $(patsubst %,srcs/%,$(SRC1)) \
		$(patsubst %,srcs/btree/%,$(SRC2)) \
		$(patsubst %,srcs/content/%,$(SRC3)) \
		$(patsubst %,srcs/draw/%,$(SRC4))  \
		$(patsubst %,srcs/option/%,$(SRC5)) \
		$(patsubst %,srcs/sort/%,$(SRC6)) \
		$(patsubst %,srcs/utility/%,$(SRC7)) \

IPATH = includes
VPATH = srcs

LIB = srcs/ft_printf/libftprintf.a

all : $(NAME)

pf :
	@cd ./srcs/ft_printf/ && $(MAKE) 

$(NAME) : pf 
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) -I $(IPATH)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)
