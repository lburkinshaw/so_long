# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 14:25:07 by lburkins          #+#    #+#              #
#    Updated: 2024/03/20 11:34:22 by lburkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFILES =	so_long.c \
			init_map.c \
			check_map.c \
			error_handling.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g #remove for submit

#ADD IN MORE THINGS FOR MLX (MLX_PATH, MLX_LIB, MLX_FLAGS...)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OFILES)
	cd libft && make all
	cc $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

libft:
	make -C libft

clean:
	rm -f $(OFILES)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re