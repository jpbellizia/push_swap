# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/22 01:46:28 by jpaulo-p          #+#    #+#              #
#    Updated: 2026/07/22 01:46:32 by jpaulo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= libft
PRINTF_DIR	= printf

LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a

HEADER		= includes/push_swap.h
INCLUDES	= -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)

# Ao criar um .c novo, acrescente o caminho dele nesta lista.
SRC			=	srcs/main.c					\
				srcs/parsing/parse.c		\
				srcs/parsing/check.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

norm:
	norminette srcs includes $(LIBFT_DIR) $(PRINTF_DIR)

.PHONY: all clean fclean re norm
