/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:45:35 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/19 15:57:52 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_mandelbrot(t_data *data, t_fractal *fractal)
{
	double	temp;
	int		iter;

	temp = 0;
	iter = -1;
	while (fractal->pixel.x < W_WIDTH)
	{
		while (fractal->pixel.y < W_HEIGHT)
		{
			fractal->c.x = (fractal->pixel.x / W_WIDTH)
				* (fractal->max.x - fractal->min.x)
				+ fractal->f_center.x - (fractal->max.x - fractal->min.x) / 2;
			fractal->c.y = (fractal->pixel.y / W_HEIGHT)
				* (fractal->max.y - fractal->min.y)
				+ fractal->f_center.y - (fractal->max.y - fractal->min.y) / 2;
			fractal->z.x = 0;
			fractal->z.y = 0;
			while (++iter < MAX_ITER && (fractal->z.x * fractal->z.x)
				+ (fractal->z.y * fractal->z.y) <= 4)
			{
				temp = (fractal->c.x * fractal->c.x)
					- (fractal->c.y * fractal->c.y)
					+ fractal->c.x;
				fractal->z.y = (2 * fractal->z.x * fractal->z.y) + fractal->c.y;
				fractal->z.x = temp;
			}
			if (iter < MAX_ITER - 1)
				img_pix_put(&data->img, (int)fractal->pixel.x,
					(int)fractal->pixel.y, 0xFFFFFF);
			else
				img_pix_put(&data->img, (int)fractal->pixel.x,
					(int)fractal->pixel.y, 0x000000);
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
