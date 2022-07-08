# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 11:31:01 by jmehlig           #+#    #+#              #
#    Updated: 2021/09/13 12:02:35 by jmehlig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

COMPILER = gcc

CFLAGS = -Wall -Wextra -Werror -c

LIBFT_PATH =./libft/

MAKE = make

SRC = ft_cases.c\
ft_printf.c\
ft_unsigned.c\
ft_utils.c\

OBJ = $(SRC:.c=.o)

LIB_OBJ = $(LIBFT_PATH:.c=.o)

all: $(NAME)

$(NAME): *.c
	Make -C ./libft
	cp ./libft/libft.a $(NAME)
	${COMPILER} $(CFLAGS) $(SRC)
	ar rc $(NAME) *.o

libft:
	cd /libft make
	ar rc $(NAME) *.o

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)
re: fclean all

bonus: all
