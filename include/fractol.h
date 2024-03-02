/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:17:21 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/02 14:07:20 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
typedef struct s_Vec2
{
	double	a;
	double	b;
}	t_Vec2;

typedef struct s_param
{
	char		*name;
	int			ac;
	mlx_t		*mlx;
	mlx_image_t *img;
	double		shift_x;
	double		shift_y;
	double		zoom;
	int			max_itr;
	t_Vec2		julia;
	double		shift_color;
	int			height;
	int			width;
}	t_param;
// Exit the program as failure.
void	draw_mandelbrot(t_param *param);
// void	draw_julia(t_param *param, t_range range, t_Vec2 c);
void	draw_julia(t_param *param);
void	render(t_param *param);
void	put_color(int it, int x, int y, t_param *param, int fractol_clolor);
/* math */
t_Vec2  converte(t_param *param, t_Vec2 c);
t_Vec2	add_vec2(t_Vec2 a, t_Vec2 b);
t_Vec2	sqrt_complex(t_Vec2 z);

/*hook*/

void	my_scrollhook(double xdelta, double ydelta, void* param);
void	my_keyhook(mlx_key_data_t keydata, void* param);
void	resize_func(int w, int h, void *param);

/* libft */
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(const char *s, int fd);
double	ft_atof(const char *str);
void	ft_error(const char *str);
#endif // !FRACTOL_H
