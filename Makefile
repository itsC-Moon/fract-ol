# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:24:45 by hibenouk          #+#    #+#              #
#    Updated: 2024/02/29 20:47:49 by hibenouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addprefix ./src/, main.c mandelbrot.c helper.c julia.c hook.c ft_atof.c helper2.c)

OBJ = $(SRC:.c=.o)

INC = -Iinclude -IMLX42/include

MLX = ./MLX42/build/libmlx42.a

LIB =  -L/Users/hibenouk/.brew/lib  -lglfw \
	   -lm  -framework Cocoa -framework OpenGL -framework IOKit

NAME = fractol

CFALGS = -O3 -Wall -Wextra -Werror -Ofast
 
CC  = cc

all : $(NAME)

$(NAME) : $(OBJ) $(MLX)
	$(CC) $(CFALGS) $(INC) $(MLX) $(LIB) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) -c $(INC) $(CFALGS) $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
re : fclean all
