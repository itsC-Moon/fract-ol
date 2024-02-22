/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:17:21 by hibenouk          #+#    #+#             */
/*   Updated: 2024/02/22 12:02:47 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define MAX_ITERS 30
typedef struct s_Vec2
{
	double	a;
	double	b;
}	t_Vec2;
typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_param
{
	mlx_t		*mlx;
	mlx_image_t *img;
}	t_param;
// Exit the program as failure.
void	draw_mandelbrot(t_param *param, t_range range, t_range mov);
void	draw_julia(t_param *param, t_range range, t_Vec2 c);
/* math */
t_Vec2 converte(t_range old, t_range new, t_Vec2 c);
t_Vec2	add_vec2(t_Vec2 a, t_Vec2 b);
t_Vec2	sqrt_complex(t_Vec2 z);

#endif // !FRACTOL_H
