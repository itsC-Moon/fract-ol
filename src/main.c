/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:17:32 by hibenouk          #+#    #+#             */
/*   Updated: 2024/02/22 12:15:42 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"
#include <stdio.h>
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	static t_range range = {.min = -2, .max = +2};
	static t_range mov = {.min = 0, .max = 0};
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(((t_param*)param)->mlx);
		exit(0);
	}
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
	{
		range.max += .15;
		range.min -= .15;
		printf("a = %lf, b = %lf\n",range.max, range.min);
		// draw_julia(param, range, (t_Vec2){.a =-0.835, .b= -0.2321});
		draw_mandelbrot((t_param*)param, range, mov);	
	}
	else if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
	{
		range.max -= .15;
		range.min += .15;
		printf("a = %lf, b = %lf\n",range.max, range.min);
		// draw_julia(param, range, (t_Vec2){.a =-0.835, .b= -0.2321});
		draw_mandelbrot((t_param*)param, range,mov);	
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		// mov.max -= 50;
		mov.min -= 50;
		printf("a = %lf, b = %lf\n",mov.max, mov.min);
		draw_mandelbrot((t_param*)param, range,mov);	
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		// mov.max -= 50;
		mov.min += 50;
		printf("a = %lf, b = %lf\n",mov.max, mov.min);
		draw_mandelbrot((t_param*)param, range, mov);	
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		mov.max -= 50;
		// mov.min -= 50;
		printf("a = %lf, b = %lf\n",mov.max, mov.min);
		draw_mandelbrot((t_param*)param, range, mov);	
	}
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		mov.max += 50;
		// mov.min += 50;
		printf("a = %lf, b = %lf\n",mov.max, mov.min);
		draw_mandelbrot((t_param*)param, range,mov);	
	}
}

int32_t main(void)
{
	t_param param;

	param.img = NULL;
	param.mlx = mlx_init(600, 600, "fractol", true);
	if (!param.mlx)
		ft_error();
	draw_mandelbrot(&param, (t_range){.min = -2, .max = 2},(t_range){.min = 0, .max = 0});	
	// draw_julia(&param, (t_range){.min = -0.01, .max = 0.02}, (t_Vec2){.a =-0.835, .b= -0.2321});
	mlx_key_hook(param.mlx, my_keyhook, &param);
	mlx_image_to_window(param.mlx, param.img, 0, 0);
	mlx_loop(param.mlx);
	mlx_terminate(param.mlx);
	return (EXIT_SUCCESS);
}
