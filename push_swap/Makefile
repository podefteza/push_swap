# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 16:17:04 by carlos-j          #+#    #+#              #
#    Updated: 2024/08/03 16:18:50 by carlos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# REMOVE LATER print_stack.c
SRCS = push_swap.c \
		checker.c \
		print_stack.c \
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
			utils/ft_strdup.c \
			utils/ft_strlen.c \
			utils/ft_substr.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

all: ${NAME}

GREEN = \033[0;32m
RESET = \033[0m

${NAME}: ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "$(GREEN)Compilation successful.$(RESET)"

clean:
	@rm -f ${OBJS}
	@echo "$(GREEN)Object files removed.$(RESET)"

fclean: clean
	@rm -f ${NAME}
	@echo "$(GREEN)Executable removed.$(RESET)"

re: fclean all
	@echo "$(GREEN)Recompiled all files.$(RESET)"

.PHONY: all clean fclean re

