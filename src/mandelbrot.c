/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:33:58 by hibenouk          #+#    #+#             */
/*   Updated: 2024/02/22 11:35:45 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

int itration(t_Vec2 c, mlx_t *mlx, t_range range)
{
	int i;
	t_Vec2 z;

	z = (t_Vec2){0};
	c = converte((t_range){mlx->width, mlx->height}, range, c);
	i = 0;
	while (i < MAX_ITERS)
	{
		z = sqrt_complex(z);
		z = add_vec2(z, c);
		if (z.a * z.a + z.b * z.b >= 4.0)
			return i;
		i++;
	}
	return (MAX_ITERS);
}

void	draw_mandelbrot(t_param *param, t_range range, t_range mov)
{
	uint32_t x;
	uint32_t y;
	int it;
	
	if (!param->img)
		param->img = mlx_new_image(param->mlx, param->mlx->width, param->mlx->width);
	x = 0;
	while (x < param->img->width)
	{
		y = 0;
		while (y < param->img->height)
		{
			it  = itration((t_Vec2){.a = x + mov.min, .b = y + mov.max}, param->mlx, range);
			if (it == MAX_ITERS)
				it = 0x000000FF;
			else
				it = 0xFFAEFF00 | it;
			mlx_put_pixel(param->img, x, y, it);
			y++;
		}
		x++;

	}
}
