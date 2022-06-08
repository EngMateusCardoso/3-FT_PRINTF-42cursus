# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 00:17:40 by matcardo          #+#    #+#              #
#    Updated: 2022/06/08 04:44:56 by matcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

#src
SRC			= ft_printf.c \
			formats.c
HEADER		= ft_printf.h
#bonus
#libft
LIBFT		= ./Libft/libft.a
DIR_LIBFT	= ./Libft

CC = gcc
FLAGS = -Wextra -Wall -Werror

all:		${NAME}

${LIBFT}:
			make -C ${DIR_LIBFT} all
			make -C ${DIR_LIBFT} clean
	
${NAME}:	${SRC} ${HEADER} ${LIBFT}
			${CC} ${FLAGS} ${SRC} ${HEADER} ${LIBFT} && ./a.out

all:		${NAME}
