/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:17 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/05 09:35:38 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	iterate_complex(t_data *data)
{
	int		iter;
	double	temp;

	iter = -1;
	temp = 0;
	while (++iter < MAX_ITER && (data->f->z.x * data->f->z.x) + (data->f->z.y * data->f->z.y) <= 4)
	{
		temp = (data->f->z.x * data->f->z.x) - (data->f->z.y * data->f->z.y) + data->f->c.x;
		data->f->z.y = (2 * data->f->z.x * data->f->z.y) + data->f->c.y;
		data->f->z.x = temp;
	}
	get_colour(data, iter);
	return ;
}

void	set_mdb_range(t_fractal *fractal)
{
	fractal->f_center.x = -0.75 * fractal->zoom;
	fractal->f_center.y = -1 * fractal->zoom;
	fractal->max.x = 2 * fractal->zoom;
	fractal->max.y = 2 * fractal->zoom;
	fractal->min.x = -1.5 * fractal->zoom;
	fractal->min.y = 0 * fractal->zoom;
	fractal->c.x = 0;
	fractal->c.y = 0;
	return ;
}

void	set_julia_range(t_fractal *fractal, int flag)
{
	fractal->max.x = 2 * fractal->zoom;
	fractal->max.y = 2 * fractal->zoom;
	fractal->min.x = -2 * fractal->zoom;
	fractal->min.y = -2 * fractal->zoom;
	if (flag == 2)
	{
		fractal->c.x = 0.285;
		fractal->c.y = 0.01;
		fractal->f_center.x = fractal->c.x * fractal->zoom;
		fractal->f_center.y = fractal->c.y * fractal->zoom;
	}
	return ;
}
