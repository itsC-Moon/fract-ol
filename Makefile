# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:24:45 by hibenouk          #+#    #+#              #
#    Updated: 2024/03/02 13:08:34 by hibenouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = $(addprefix ./src/, mandelbrot.c helper.c julia.c ft_atof.c helper2.c)

SRC = $(addprefix ./src/, main.c hook.c) $(LIBFT)
OBJ = $(SRC:.c=.o)


BSRC = $(addprefix ./bonus/, main_bonus.c  hooks_bonus.c) $(LIBFT)
BOBJ = $(BSRC:.c=.o)

INC = -Iinclude -IMLX42/include

MLX = ./MLX42/build/libmlx42.a

LIB =  -L/Users/hibenouk/.brew/lib  -lglfw \
	   -lm  -framework Cocoa -framework OpenGL -framework IOKit

NAME 		= fractol
NAME_BONUS 	= fractol_bonus

CFALGS = -O3 -Wall -Wextra -Werror -Ofast
 
CC  = cc

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFALGS) $(INC) $(MLX) $(LIB) $(OBJ) -o $(NAME)

$(NAME_BONUS) : $(BOBJ)
	$(CC) $(CFALGS) $(INC) $(MLX) $(LIB) $(BOBJ) -o $(NAME_BONUS)

%.o : %.c
	$(CC) -c $(INC) $(CFALGS) $< -o $@

clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
re : fclean all
