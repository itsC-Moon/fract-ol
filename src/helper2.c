/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:21:09 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/02 14:08:13 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_error(const char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}


void put_color(int it, int x, int y, t_param *param, int fractol_clolor)
{
	if (it == param->max_itr)
		it = fractol_clolor;
	else if (it < param->max_itr / 8)
		it = 0x205295FF;
	else if (it < param->max_itr / 4)
		it = 0x2C74B3FF;
	else if (it < param->max_itr / 2)
		it = 0x59C1BDFF;
	else
		it = 0x8FE3CFFA;
	mlx_put_pixel(param->img, x, y, it * param->shift_color);
}
