# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:24:45 by hibenouk          #+#    #+#              #
#    Updated: 2024/02/21 15:05:29 by hibenouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addprefix ./src/, main.c mandelbrot.c helper.c julia.c)

OBJ = $(SRC:.c=.o)

INC = -Iinclude -IMLX42/include

LIB = ./MLX42/build/libmlx42.a -L/Users/hibenouk/.brew/lib -ldl  -lglfw -pthread -lm  -framework Cocoa -framework OpenGL -framework IOKit

NAME = fractol

CFALGS = -O3 -Wall -Wextra -Werror -Ofast
 
CC  = cc

run : $(NAME)
	./$(NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFALGS) $(INC) $(LIB) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) -c $(INC) $(CFALGS) $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
