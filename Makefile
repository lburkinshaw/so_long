# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 14:25:07 by lburkins          #+#    #+#              #
#    Updated: 2024/04/10 14:40:03 by lburkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g #remove "-g" for submit
SRCS		=	so_long.c \
				init_map.c \
				check_map.c \
				check_route.c \
				flood_fill.c \
				mlx_test.c \
				load_images.c \
				moves.c \
				directions.c \
				so_long_utils.c \
				error_handling.c
			
OBJS		=	$(SRCS:.c=.o)
HEADER		=	so_long.h
GLFW_DIR	=	/Users/lburkins/.brew/opt/glfw/lib
MLX			=	MLX42/build/libmlx42.a
MLX_HEADER	=	MLX42/include/MLX42/MLX42.h
LIBFT		=	libft/libft.a

all:			$(NAME)

$(LIBFT):
					@make -C ./libft

$(MLX):
					@cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME):		$(OBJS) $(MLX) $(LIBFT) $(HEADER)
					@$(CC) $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L$(GLFW_DIR) -lglfw -I $(MLX_HEADER) -o $(NAME)
					@echo "  *************  "
					@echo "  ** so_long **  "
					@echo "  *************  "
					@echo "Compiled ✅"

%.o:			%.c
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@rm -f $(OBJS)
					@rm -rf MLX42/build
					make fclean -C ./libft

fclean:			clean
					@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re