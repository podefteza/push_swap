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
		utils/checker.c \
		utils/exit.c \
		utils/min_max.c \
		utils/small_stack.c \
		utils/sort.c \
		utils/split_args.c \
		operations/push.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap.c \
		libft/ft_atoi.c \
		libft/ft_isdigit.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstlast.c \
		libft/ft_lstnew.c \
		libft/ft_lstsize.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_substr.c

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
