/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:37 by hibenouk          #+#    #+#             */
/*   Updated: 2024/02/21 19:12:20 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static int itration(t_Vec2 c, mlx_t *mlx, t_Vec2 z, t_range range)
{
	int i;

	z = converte((t_range){mlx->width, mlx->height}, range, z);
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
void draw_julia(t_param *param, t_range range, t_Vec2 c)
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
			it  = itration(c, param->mlx, (t_Vec2){.a = x, .b = y}, range);
			if (it == MAX_ITERS)
				it = 0x000000FF;
			else
				it = 0xFF00FF00 | it;
			//  hue = int(255 * m / MAX_ITER)
			// saturation = 255
			// value = 255 if m < MAX_ITER else 0			it = 0x000000FF;
			mlx_put_pixel(param->img, x, y, it);
			y++;
		}
		x++;

	}
}
