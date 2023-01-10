# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 07:58:55 by ayakoubi          #+#    #+#              #
#    Updated: 2023/01/09 19:25:28 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
SRC		=	pipex.c ft_printf.c ft_putchar.c ft_putnbr.c \
			ft_putstr.c ft_putuns.c ft_puthex.c ft_strncmp.c\
			ft_split.c ft_strjoin.c ft_strlen.c ft_substr.c \
			ft_strchr.c ft_putstr_fd.c utils.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
