# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamin <kamin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 05:43:04 by kamin             #+#    #+#              #
#    Updated: 2021/12/09 05:58:12 by kamin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

INCLUDES	=	includes

DIR_S		=	src/

SRC		=	main.c \
			push_swap.c \

OBJS	=	$(addorefix $(DIR_S),$(SRC:.c=.o))

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra -g3

$(NAME):$(OBJS)
		$(CC) $(FLAGS) $(addprefix $(DIR_S),$(SRC)) -I $(INCLUDES) -o $(NAME)

all:
		$(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all