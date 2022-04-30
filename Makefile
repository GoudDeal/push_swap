# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 19:51:49 by dcyprien          #+#    #+#              #
#    Updated: 2022/01/11 21:17:24 by dcyprien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/big_sort.c\
			./srcs/push_ss.c\
			./srcs/push_swap_utils.c\
			./srcs/push_swap.c\
			./srcs/rotate.c\
			./srcs/sort_2_3.c\
			./srcs/sort_4.c\
			./srcs/sort_5.c\
			./srcs/stack_parsing.c\
			./srcs/ft_atoi.c\
			./srcs/ft_isdigit.c\
			./srcs/ft_lstnew.c\
			./srcs/ft_memmove.c\
			./srcs/ft_memcpy.c\
			./srcs/ft_putchar_fd.c\
			./srcs/ft_putstr_fd.c\
			./srcs/ft_strdup.c\
			./srcs/ft_strlen.c\
			./srcs/ft_strncmp.c

NAME	=	push_swap

CC		=	gcc 

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f


$(NAME):	${OBJS}
			${CC} ${CCFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY = all clean fclean re

