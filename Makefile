# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 00:17:40 by matcardo          #+#    #+#              #
#    Updated: 2022/06/05 01:17:29 by matcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

#src
SRC			= ft_printf.c
HEADER		= ft_printf.h
SRC_DIR		= ./ft_printf_mandatory
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
	
${NAME}:	${SRC_DIR}/${SRC} ${SRC_DIR}/${HEADER} ${LIBFT}
			${CC} ${SRC_DIR}/${SRC} ${SRC_DIR}/${HEADER} ${LIBFT} && ./a.out

all:		${NAME}

#gcc ft_printf_mandatory/ft_printf.c ft_printf_mandatory/ft_printf.h Libft/ft_putchar_fd.c && ./a.out