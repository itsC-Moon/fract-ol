/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:06 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/31 00:03:26 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_putstr_fd(const char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
}

/*
 *	
	OldRange = (OldMax - OldMin)
	NewRange = (NewMax - NewMin) 
	NewValue = (((OldValue - OldMin) * NewRange) / OldRange) + NewMin
*/

double map(double a, double n_max, double n_min, double o_max)
{
	return ((a * (n_max - n_min) ) / o_max + n_min);
}

t_Vec2	sqrt_complex(t_Vec2 z)
{
	t_Vec2	s;

	s.a = z.a * z.a - (z.b * z.b);
	s.b = 2 * z.a * z.b;
	return (s);
}

t_Vec2	add_vec2(t_Vec2 a, t_Vec2 b)
{
	return ((t_Vec2){.a = a.a + b.a, .b = a.b + b.b});
}
