/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:33:58 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/31 00:04:15 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	itration(t_Vec2 c, t_param *param)
{
	int		i;
	t_Vec2	z;

	z = (t_Vec2){0};

	c.a = map(c.a, 2, -2, param->width) * param->zoom + param->shift_x;
	c.b = map(c.b, 2, -2, param->height) * param->zoom + param->shift_y;
	i = 0;
	while (i < param->max_itr)
	{
		z = sqrt_complex(z);
		z = add_vec2(z, c);
		if (z.a * z.a + z.b * z.b >= 4.0)
			return (i);
		i++;
	}
	return (param->max_itr);
}

void	draw_mandelbrot(t_param *param)
{
	int32_t		x;
	int32_t		y;
	int			it;

	x = 0;
	while (x < param->width)
	{
		y = 0;
		while (y < param->height)
		{
			it = itration((t_Vec2){x, y}, param);
			put_color(it, (t_Vec2){x, y}, param, 0x000000FF);
			y++;
		}
		x++;
	}
}
