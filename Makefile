# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awyart <awyart@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 22:10:59 by awyart            #+#    #+#              #
#    Updated: 2017/09/08 11:27:38 by awyart           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_ls
FLAGS = -Werror -Wall -Wextra

SRC1 = main.c\

SRC = $(patsubst %,srcs/%,$(SRC1)) \

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
