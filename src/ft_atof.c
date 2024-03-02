/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:54:49 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/02 12:09:02 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double ft_atof2(const char *str)
{
	double	res_r;
	int		i;
	double	zero;

	zero = 1;
	i = 0;
	res_r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i <= 6)
		{
			res_r = res_r * 10 + str[i] - 48;
			zero *= 10;
		}
		i++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
		ft_error("unvalid number\n");
	res_r = res_r / zero;
	return (res_r);

}
double ft_atof(const char *str)
{
	int		i;
	int		sing;
	double	res_l;
	
	if (!str || !*str)
		ft_error("unvalid number\n");
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	sing = (str[i] == '-') * -1 + (str[i] != '-');	
	i += (str[i] == '-' || str[i] == '+');
	res_l = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res_l = res_l * 10 + str[i] - 48;
		if (res_l > 2000)
			ft_error("Number are to large for julia set\n");
		i++;
	}
	if (str[i] && str[i] != '.')
		ft_error("unvalid number\n");
	if (str[i])
		res_l += ft_atof2(str + i + 1);
	res_l *= sing;
	return(res_l);
}

