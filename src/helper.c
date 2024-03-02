/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:06 by hibenouk          #+#    #+#             */
/*   Updated: 2024/03/02 12:12:38 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <assert.h>
#include <stdint.h>

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

t_Vec2	converte(t_param *param, t_Vec2 c)
{
	c.a = (c.a / param->width) * 4 - 2;
	c.b = (c.b / param->height) * 4 - 2;
	c.a = c.a * param->zoom + param->shift_x;
	c.b = c.b * param->zoom + param->shift_y;
	return (c);
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
