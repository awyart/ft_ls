# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awyart <awyart@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 22:10:59 by awyart            #+#    #+#              #
#    Updated: 2017/09/08 11:24:28 by awyart           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror -O3
NAME = libftprintf.a
SRC1 = ft_printf.c\

SRC2 = utility/ft_putchar.c\
	utility/ft_putchar_unicode.c\
	utility/ft_putnchar.c\
	utility/ft_putstr.c\
	utility/ft_strlen.c\
	utility/ft_strchr.c\
	utility/ft_itoab_l.c\
	utility/ft_itoab_ll.c\
	utility/ft_itoa.c\
	utility/ft_down.c\
	utility/ft_isdigit.c \
	utility/ft_strcpy.c\
	utility/ft_ent.c

SRC3 = get_info/get_flag.c\
	get_info/cv_s.c\
	get_info/cv_sm.c\
	get_info/cv_d.c\
	get_info/cv_f.c\
	get_info/cv_fm.c\
	get_info/cv_dm.c\
	get_info/cv_o.c\
	get_info/cv_om.c\
	get_info/cv_p.c\
	get_info/cv_u.c\
	get_info/cv_um.c\
	get_info/cv_x.c\
	get_info/cv_xm.c\
	get_info/cv_im.c\
	get_info/cv_c.c\
	get_info/cv_cm.c\
	get_info/cv_b.c\
	get_info/cv_n.c\
	get_info/cv_nm.c\
	get_info/cv_per.c\

SRC = $(SRC1) $(SRC2) $(SRC3) 
OBJ1 = $(patsubst %.c,%.o,$(SRC1))
OBJ2 = $(patsubst utility/%.c,%.o,$(SRC2))
OBJ3 = $(patsubst get_info/%.c,%.o,$(SRC3))
OBJ = $(OBJ1) $(OBJ2) $(OBJ3)

IPATH = includes
VPATH = srcs

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(CFLAGS) -c $^ -I $(IPATH) 
	@ar rc $(NAME) $(OBJ)  
	@ranlib $(NAME)
	
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)
