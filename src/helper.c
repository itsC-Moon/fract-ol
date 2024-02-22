/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:06 by hibenouk          #+#    #+#             */
/*   Updated: 2024/02/21 13:53:23 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// new_value = ( (old_value - old_min) / (old_max - old_min) ) * (new_max - new_min) + new_min
	// c.a = ((c.a - 0) /old->width - 0 ) * (2 - -2) + -2;
	// c.b = ((c.b - 0) /old->height - 0 ) * (2 - -2) + -2;
t_Vec2 converte(t_range old, t_range new, t_Vec2 c)
{
	c.a = ((c.a - 0) /old.min - 0 ) * (new.max - new.min) + new.min;
	c.b = ((c.b - 0) /old.max - 0 ) * (new.max - new.min) + new.min;
	return (c);
}

t_Vec2 sqrt_complex(t_Vec2 z)
{
	t_Vec2	s;

	s.a = z.a * z.a - (z.b * z.b);
	s.b = 2 * z.a * z.b;
	return (s);
}

t_Vec2 add_vec2(t_Vec2 a, t_Vec2 b)
{
	return ((t_Vec2){.a = a.a + b.a, .b = a.b + b.b});
}
