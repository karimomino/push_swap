# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamin <kamin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 05:43:04 by kamin             #+#    #+#              #
#    Updated: 2022/01/08 08:07:17 by kamin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

INCLUDES	=	includes

DIR_S		=	src/

SRC		=	main.c \
			push_swap.c \
			error_handling.c \
			utils.c \
			push_stack.c \
			rotate_stack.c \
			swap_stack.c \
			quicksort.c \

OBJS	=	$(addorefix $(DIR_S),$(SRC:.c=.o))

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra -g3

$(NAME): $(OBJS)
		@$(MAKE) -C libft
		@echo "Make libft successful"
		@mv libft/libft.a libft.a
		$(CC) $(FLAGS) $(addprefix $(DIR_S),$(SRC)) libft.a -I$(INCLUDES) -o $(NAME)

all:$(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
		rm -f libft.a
		rm -f libft/*.o
		rm -f libft/libft.a

re:		fclean all
