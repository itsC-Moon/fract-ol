/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:23:07 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/02 14:30:50 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"
#include <stdio.h>

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_param *ptr;
	// int		x;
	// int		y;
	ptr = param;
	if (ydelta > 0)
		ptr->zoom += ptr->zoom * 0.1;
	else if (ydelta < 0)
		ptr->zoom -= ptr->zoom * 0.1;
	// mlx_get_mouse_pos(ptr->mlx, &x, &y);
	(void)xdelta;
	// if (x  > ptr->width / 2)
	// 	ptr->shift_x += 0.1 * ptr->zoom;
	// else
	// 	ptr->shift_x -= 0.1 * ptr->zoom;
	// if (y  > ptr->height / 2)
	// 	ptr->shift_y += 0.1 * ptr->zoom;
	// else
	// 	ptr->shift_y -= 0.1 * ptr->zoom;
	// if (ydelta < 0)
	// {
	// 	if (x  > ptr->width / 2)
	// 		ptr->shift_x += 0.1 * ptr->zoom;
	// 	else
	// 		ptr->shift_x -= 0.1 * ptr->zoom;
	// 	if (y  > ptr->height / 2)
	// 		ptr->shift_y += 0.1 * ptr->zoom;
	// 	else
	// 		ptr->shift_y -= 0.1 * ptr->zoom;
	// }
	// else if (ydelta > 0)
	// {
	// 	if (x  > ptr->width / 2)
	// 		ptr->shift_x -= 0.1 * ptr->zoom;
	// 	else
	// 		ptr->shift_x += 0.1 * ptr->zoom;
	// 	if (y  > ptr->height / 2)
	// 		ptr->shift_y -= 0.1 * ptr->zoom;
	// 	else
	// 		ptr->shift_y += 0.1 * ptr->zoom;
	// }
	render(param);
}

void resize_func(int w, int h, void *param)
{
	t_param *ptr;

	ptr = param;
	if (mlx_resize_image(ptr->img, w, h) == false)
		ft_error("image Error");
	ptr->height = h;
	ptr->width = w;
	render(param);
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_param *ptr;

	ptr = param;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		ptr->shift_x += 0.3 * ptr->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		ptr->shift_x -= 0.3 * ptr->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		ptr->shift_y -= 0.3 * ptr->zoom;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		ptr->shift_y += 0.3 * ptr->zoom;
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_RELEASE)
		ptr->max_itr += 5;
	else if (keydata.key == MLX_KEY_T && keydata.action == MLX_RELEASE)
		ptr->max_itr -= 5;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(ptr->mlx);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ptr->shift_color += 0.1 * ptr->shift_color;
	else if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
		ptr->shift_color -= 0.1 * ptr->shift_color;
	else
		return;
	render(param);
}
