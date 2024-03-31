/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:57:26 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/31 00:09:48 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdint.h>

static t_Vec2	_sqrt_complex(t_Vec2 z)
{
	t_Vec2	s;

	s.a = z.a * z.a - (z.b * z.b);
	s.b = 2 * z.a * z.b;
	s.b = (s.b > 0) * s.b - (s.b < 0) * s.b;
	return (s);
}

static int	itration(t_Vec2 c, t_param *param)
{
	int		i;
	t_Vec2	z;

	c.a = map(c.a, 2, -2, param->width) * param->zoom + param->shift_x;
	c.b = map(c.b, 2, -2, param->height) * param->zoom + param->shift_y;
	z = (t_Vec2){0};
	i = 0;
	while (i < param->max_itr)
	{
		z = _sqrt_complex(z);
		z = add_vec2(z, c);
		if (z.a * z.a + z.b * z.b >= 4.0)
			return (i);
		i++;
	}
	return (param->max_itr);
}

void	burning_ship(t_param *param)
{
	int32_t	x;
	int32_t	y;
	int		it;

	x = 0;
	while (x < param->width)
	{
		y = 0;
		while (y < param->height)
		{
			it = itration((t_Vec2){x, y}, param);
			put_color(it, (t_Vec2){.a = x, .b = y}, param, 0x000000FF);
			y++;
		}
		x++;
	}
}
