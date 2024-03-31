/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:54:49 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/30 22:39:04 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	inc(const char *str, int *sign)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0')
		ft_error("Invalid number\n", NULL);
	while (is_space(str[i]))
		i++;
	*sign = (str[i] == '-') * -1 + (str[i] != '-');
	i += (str[i] == '-') + (str[i] == '+');
	if (!is_digit(str[i]))
		ft_error("Invalid number\n", NULL);
	return (i);
}

static void	inc2(const char *str)
{
	int	i;

	i = (str[0] == '.');
	if (i != 0 && !is_digit(str[i]))
		ft_error("Invalid number\n", NULL);
	while (i != 0 && is_digit(str[i]))
		i++;
	while (is_space(str[i]))
		i++;
	if (str[i])
		ft_error("Invalid number\n", NULL);
}

static double	ft_atof2(const char *str)
{
	double	res_r;
	int		i;
	double	zero;

	zero = 1;
	res_r = 0;
	i = 0;
	while (is_digit(str[i]))
	{
		if (i <= 6)
		{
			res_r = res_r * 10 + str[i] - 48;
			zero *= 10;
		}
		i++;
	}
	res_r = res_r / zero;
	return (res_r);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	res_l;

	i = 0;
	res_l = 0.0f;
	i = inc(str, &sign);
	while (is_digit(str[i]))
	{
		res_l = res_l * 10 + str[i++] - 48;
		if (res_l > 2147483648.0f)
			ft_error("Invalid number\n", NULL);
	}
	inc2(str + i);
	if (str[i] == '.')
		res_l += ft_atof2(str + i + 1);
	res_l = res_l * sign;
	return (res_l);
}
