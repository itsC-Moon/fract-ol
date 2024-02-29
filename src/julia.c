/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:37 by hibenouk          #+#    #+#             */
/*   Updated: 2024/02/29 21:45:10 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
static int	itration(t_param *param, t_Vec2 z)
{
	int		i;

	z = converte(param, z);
	i = 0;
	while (i < param->max_itr)
	{
		z = sqrt_complex(z);
		z = add_vec2(z, param->julia);
		if (z.a * z.a + z.b * z.b >= 4.0)
			return i;
		i++;
	}
	return (param->max_itr);
}

void	draw_julia(t_param *param)
{
	int32_t	x;
	int32_t	y;
	int			it;
	
	x = 0;
	while (x < param->width)
	{
		y = 0;
		while (y < param->height)
		{
			it  = itration(param, (t_Vec2){.a = x, .b = y});
			if (it == param->max_itr)
				it = 0x000000FF;
			else
				it = (0xA2FF8600 | it % 256 );
			mlx_put_pixel(param->img, x, y, it);
			y++;
		}
		x++;

	}
}
