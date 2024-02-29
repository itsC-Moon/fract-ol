/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:33:58 by hibenouk          #+#    #+#             */
/*   Updated: 2024/02/29 21:34:01 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>


int itration(t_Vec2 c, t_param *param)
{
	int i;
	t_Vec2 z;

	z = (t_Vec2){0};
	c = converte(param, c);
	i = 0;
	while (i < param->max_itr)
	{
		z = sqrt_complex(z);
		z = add_vec2(z, c);
		if (z.a * z.a + z.b * z.b >= 4.0)
			return i;
		i++;
	}
	return (param->max_itr);
}

void	draw_mandelbrot(t_param *param)
{
	int32_t x;
	int32_t y;
	int it;
	
	x = 0;
	while (x < param->width)
	{
		y = 0;
		while (y < param->height)
		{
			it  = itration((t_Vec2){.a = x, .b = y}, param);
			it = (it == param->max_itr) * 0x000000FF + (it != param->max_itr) * (0xFFAEFF00 | it);
			mlx_put_pixel(param->img, x, y, it);
			y++;
		}
		x++;

	}
}
