/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:45:35 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/03 11:47:09 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_mandelbrot(t_data *data, t_fractal *fractal)
{
	while (fractal->pixel.x < W_WIDTH)
	{
		fractal->pixel.y = 0;
		while (fractal->pixel.y < W_HEIGHT)
		{
			fractal->c.x = fractal->min.x + (fractal->pixel.x / (double)W_WIDTH)
				* (fractal->max.x - fractal->min.x) + fractal->f_center.x
				+ fractal->offset.x;
			fractal->c.y = fractal->min.y + (fractal->pixel.y
					/ (double)W_HEIGHT) * (fractal->max.y - fractal->min.y)
				+ fractal->f_center.y + fractal->offset.y;
			fractal->z.x = 0;
			fractal->z.y = 0;
			iterate_complex(data, fractal);
			fractal->pixel.y++;
		}
		fractal->pixel.x++;
	}
	return (0);
}

int	ft_julia_static(t_data *data, t_fractal *fractal)
{
	if (data && fractal)
		return (0);
	else
		return (0);
}
