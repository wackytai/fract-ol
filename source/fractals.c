/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:45:35 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/08 09:53:26 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_mandelbrot(t_data *data)
{
	while (data->f->pixel.x < W_WIDTH)
	{
		data->f->pixel.y = 0;
		while (data->f->pixel.y < W_HEIGHT)
		{
			data->f->c.x = data->f->min.x + (data->f->pixel.x / (double)W_WIDTH)
				* (data->f->max.x - data->f->min.x) + data->f->f_center.x
				+ data->f->offset.x;
			data->f->c.y = data->f->min.y + (data->f->pixel.y
					/ (double)W_HEIGHT) * (data->f->max.y - data->f->min.y)
				+ data->f->f_center.y + data->f->offset.y;
			data->f->z.x = 0;
			data->f->z.y = 0;
			iterate_complex(data);
			data->f->pixel.y++;
		}
		data->f->pixel.x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}

int	ft_julia_static(t_data *data)
{
	while (data->f->pixel.x < W_WIDTH)
	{
		data->f->pixel.y = 0;
		while (data->f->pixel.y < W_HEIGHT)
		{
			data->f->z.x = data->f->min.x + (data->f->max.x - data->f->min.x)
				* data->f->pixel.x / (double)W_WIDTH + data->f->offset.x;
			data->f->z.y = data->f->max.y - (data->f->max.y - data->f->min.y)
				* data->f->pixel.y / (double)W_HEIGHT - data->f->offset.y;
			iterate_complex(data);
			data->f->pixel.y++;
		}
		data->f->pixel.x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}

int	ft_burning_ship(t_data *data)
{
	while (data->f->pixel.x < W_WIDTH)
	{
		data->f->pixel.y = 0;
		while (data->f->pixel.y < W_HEIGHT)
		{
			data->f->c.x = data->f->min.x + (data->f->pixel.x / (double)W_WIDTH)
				* (data->f->max.x - data->f->min.x) + data->f->offset.x;
			data->f->c.y = data->f->min.y + (data->f->pixel.y
					/ (double)W_HEIGHT) * (data->f->max.y - data->f->min.y)
				+ data->f->offset.y;
			data->f->z.x = 0;
			data->f->z.y = 0;
			iterate_abs(data);
			data->f->pixel.y++;
		}
		data->f->pixel.x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}
