/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:22:26 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/31 00:01:05 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"

void	render_bonus(t_param *param)
{
	if (ft_strcmp(param->name, "Julia") == 0)
		draw_julia(param);
	else if (ft_strcmp(param->name, "Mandelbrot") == 0)
		draw_mandelbrot(param);
	else if (ft_strcmp(param->name, "ship") == 0)
		burning_ship(param);
}

static void	usage(void)
{
	ft_putstr_fd("usage : \n", 2);
	ft_putstr_fd("./fractol Julia x y\n", 2);
	ft_putstr_fd("./fractol Mandelbrot\n", 2);
	ft_putstr_fd("./fractol ship\n", 2);
	exit(1);
}

static void	parse(t_param *param, char **argv, int ac)
{
	param->name = *(argv + 1);
	if (ft_strcmp(param->name, "Julia") == 0)
	{
		if (ac != 4)
			return (ft_putstr_fd("usage : ./fractol Julia x y\n", 2), exit(1));
		param->julia.a = ft_atof(*(argv + 2));
		param->julia.b = ft_atof(*(argv + 3));
	}
	else if (ft_strcmp(param->name, "Mandelbrot") == 0)
	{
		if (ac != 2)
			return (ft_putstr_fd("usage : ./fractol Mandelbrot\n", 2), exit(1));
	}
	else if (ft_strcmp(param->name, "ship") == 0)
	{
		if (ac != 2)
			return (ft_putstr_fd("usage : ./fractol ship\n", 2), exit(1));
	}
	else
		usage();
}

static t_param	init_param(int ac, char **argv)
{
	t_param	param;

	parse(&param, argv, ac);
	param.img = NULL;
	param.mlx = mlx_init(700, 700, "fractol", true);
	param.width = 700;
	param.height = 700;
	if (!param.mlx)
		ft_error(mlx_strerror(mlx_errno), NULL);
	param.img = mlx_new_image(param.mlx, param.mlx->width, param.mlx->width);
	if (!param.img)
		ft_error(mlx_strerror(mlx_errno), NULL);
	param.shift_x = 0;
	param.shift_y = 0;
	param.zoom = 1;
	param.max_itr = 100;
	param.shift_color = 1;
	return (param);
}

int	main(int ac, char **argv)
{
	t_param	param;

	if (ac < 2)
		usage();
	param = init_param(ac, argv);
	mlx_image_to_window(param.mlx, param.img, 0, 0);
	render_bonus(&param);
	mlx_key_hook(param.mlx, my_keyhook, &param);
	mlx_scroll_hook(param.mlx, my_scrollhook, &param);
	mlx_resize_hook(param.mlx, resize_func, &param);
	mlx_loop(param.mlx);
	mlx_terminate(param.mlx);
	mlx_delete_image(param.mlx, param.img);
	return (EXIT_SUCCESS);
}
