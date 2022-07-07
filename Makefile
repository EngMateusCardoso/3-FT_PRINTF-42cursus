# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 00:17:40 by matcardo          #+#    #+#              #
#    Updated: 2022/07/07 16:24:19 by matcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c 	\
			puthex.c	\
			putnbr.c	\
			putstr.c	\
			libft.c
OBJS		= ${SRCS:.c=.o}
HEADER		= ft_printf.h

RM			= rm -f
LIB			= ar -rcs

CC			= gcc
FLAGS		= -Wall -Werror -Wextra
.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			${LIB} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re