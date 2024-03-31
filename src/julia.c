/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:37 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/31 00:05:30 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	itration(t_param *param, t_Vec2 z)
{
	int		i;

	z.a = map(z.a, 2, -2, param->width) * param->zoom + param->shift_x;
	z.b = map(z.b, 2, -2, param->height) * param->zoom + param->shift_y;
	i = 0;
	while (i < param->max_itr)
	{
		z = sqrt_complex(z);
		z = add_vec2(z, param->julia);
		if (z.a * z.a + z.b * z.b >= 4.0)
			return (i);
		i++;
	}
	return (param->max_itr);
}

void	draw_julia(t_param *param)
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
			it = itration(param, (t_Vec2){.a = x, .b = y});
			put_color(it, (t_Vec2){.a = x, .b = y}, param, 0xFFFD8CFF);
			y++;
		}
		x++;
	}
}
