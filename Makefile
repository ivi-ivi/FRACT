# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 02:17:10 by mcrissy           #+#    #+#              #
#    Updated: 2020/08/06 02:17:10 by mcrissy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = srcs
SRC_FILE = main.c hook.c mandelbrot.c julia.c tools.c heart.c fractal.c celtic_mandelbrot.c

OBJ_D = obj
OBJ_FILE = $(SRC_FILE:.c=.o)

FLAG = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

LIFLAGS = -L libft
MLX = -O2 -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRCS)/,$(SRC_FILE))
OBJ = $(addprefix $(OBJ_D)/,$(OBJ_FILE))

all: $(NAME)
$(NAME): $(OBJ)
	@make -C libft
	@gcc $(LIFLAGS) $(MLX) $^ -o $@

$(OBJ_D)/%.o: $(SRCS)/%.c
	@mkdir $(OBJ_D) 2> /dev/null || true
	@gcc $(FLAG) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_D) 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
