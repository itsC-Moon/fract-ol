/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:38:42 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/31 00:27:09 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_param		*ptr;

	(void)xdelta;
	ptr = param;
	if (ydelta > 0)
		ptr->zoom += ptr->zoom * 0.1;
	else if (ydelta < 0)
		ptr->zoom -= ptr->zoom * 0.1;
	render(param);
}

void	resize_func(int w, int h, void *param)
{
	t_param		*ptr;

	ptr = param;
	if (mlx_resize_image(ptr->img, w, h) == false)
		ft_error(mlx_strerror(mlx_errno), ptr);
	ptr->height = h;
	ptr->width = w;
	render(param);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_param		*ptr;

	ptr = param;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_RELEASE)
		ptr->max_itr += 10 * (ptr->max_itr <= 256);
	else if (keydata.key == MLX_KEY_T && keydata.action == MLX_RELEASE)
		ptr->max_itr -= 10 * (ptr->max_itr >= 50);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_error("", param);
	else
		return ;
	render(param);
}
