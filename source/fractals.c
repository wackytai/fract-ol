/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:45:35 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/21 11:33:35 by tlemos-m         ###   ########.fr       */
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
				* (fractal->max.x - fractal->min.x) + fractal->f_center.x;
			fractal->c.y = fractal->min.y + (fractal->pixel.y
					/ (double)W_HEIGHT) * (fractal->max.y - fractal->min.y)
				+ fractal->f_center.y;
			fractal->z.x = 0;
			fractal->z.y = 0;
			iterate_complex(data, fractal);
			fractal->pixel.y++;
		}
		fractal->pixel.x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}

int	ft_julia_static(t_data *data, t_fractal *fractal)
{
	if (data && fractal)
		return (0);
	else
		return (0);
}
