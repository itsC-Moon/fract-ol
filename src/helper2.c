/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:21:09 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/30 22:36:54 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"

void	ft_error(const char *str, t_param *param)
{
	if (param)
	{
		if (param->img)
			mlx_delete_image(param->mlx, param->img);
		mlx_close_window(param->mlx);
		mlx_terminate(param->mlx);
	}
	ft_putstr_fd(str, 2);
	exit(1);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	put_color(int it, t_Vec2 coord, t_param *param, int fractol_clolor)
{
	int	r;
	int	g;
	int	b;

	r = (it * param->shift_color * 6) % 256;
	g = (it * param->shift_color * 20) % 256;
	b = (it * param->shift_color * 7) % 256;
	if (it == param->max_itr)
		it = fractol_clolor;
	else
		it = (r << 24 | g << 16 | b << 8) | 0x000000FF;
	mlx_put_pixel(param->img, coord.a, coord.b, it);
}
