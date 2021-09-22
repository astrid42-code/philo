# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 15:27:57 by asgaulti          #+#    #+#              #
#    Updated: 2021/09/22 16:29:11 by asgaulti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

# Colors
GREY = $'\x1b[30m
RED = $'\x1b[31m
GREEN = $'\x1b[32m
YELLOW = $'\x1b[33m
BLUE = $'\x1b[34m
PURPLE = $'\x1b[35m
CYAN = $'\x1b[36m
WHITE = $'\x1b[37m

SRCS	=	main.c ft_utils.c ft_print.c ft_actions.c ft_parse.c \
			ft_init.c ft_start.c ft_exit.c 

PATH_SRCS = srcs/

OBJS	=	${addprefix ${PATH_SRCS}, ${SRCS:.c=.o}}

CC		=	clang
#clang-9 
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra #-g3 -fsanitize=address


INCL	=	include

.c.o:
			${CC} ${CFLAGS} -I${INCL} -g -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
					
re:			fclean all

.PHONY:		all clean fclean re