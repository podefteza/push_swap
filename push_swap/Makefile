# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 16:17:04 by carlos-j          #+#    #+#              #
#    Updated: 2024/08/26 13:28:41 by carlos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
		checker.c \
		exit.c \
		small_stack.c \
		split_args.c \
		min_max.c \
		sort.c \
			operations/push.c \
			operations/reverse_rotate.c \
			operations/rotate.c \
			operations/swap.c \
			utils/ft_atoi.c \
			utils/ft_isdigit.c \
			utils/ft_lstadd_back.c \
			utils/ft_lstnew.c \
			utils/ft_lstlast.c \
			utils/ft_lstsize.c \
			utils/ft_split.c \
			utils/ft_strchr.c \
			utils/ft_strdup.c \
			utils/ft_strlen.c \
			utils/ft_substr.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "Compilation successful."

clean:
	@rm -f ${OBJS}
	@echo "Object files removed."

fclean: clean
	@rm -f ${NAME}
	@echo "Executable removed."

re: fclean all
	@echo "Recompiled all files."

.PHONY: all clean fclean re
