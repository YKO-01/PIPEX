# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 07:58:55 by ayakoubi          #+#    #+#              #
#    Updated: 2023/02/03 15:42:14 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
SRC		=	pipex.c check_path.c check_command.c check_script.c free_2d_arrays.c \
			ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putuns.c ft_puthex.c \
			ft_strncmp.c ft_split.c ft_strjoin.c ft_strlen.c ft_substr.c \
			ft_strchr.c ft_calloc.c ft_memset.c ft_bzero.c

OBJDIR	= obj
_OBJ	=	$(SRC:.c=.o)
OBJ		=	$(patsubst %,$(OBJDIR)/%,$(_OBJ))


CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror




all		:	$(NAME)

$(OBJDIR)/%.o:%.c
	@echo "Compiling >>>>>>>> "$<
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
	@echo "	===================="
	@echo "	 Build successful!"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "	====================="

clean	:
	@echo "====================="
	@echo "REMOVED OBJECTS"
	@rm -rf $(OBJDIR)/*.o
	@rm -rf $(OBJDIR)

fclean	:	clean
	@rm -rf $(NAME)
	@echo "====================="

re		:	fclean all

.PHONY	:	all clean fclean re
