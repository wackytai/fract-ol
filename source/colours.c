/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:59:57 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:36 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_colour(t_data *data, t_fractal *f, int iter)
{
	int	colour_1;
	int	colour_2;
	int	r;
	int	g;
	int	b;

	colour_1 = 0xFFE863;
	colour_2 = 0x47297B;
	if (iter < MAX_ITER)
	{
		r = (int)((colour_2 >> 16 & 0xFF) + ((float)iter / (float)MAX_ITER)
				* ((colour_1 >> 16 & 0xFF) - (colour_2 >> 16 & 0xFF)));
		g = (int)((colour_2 >> 8 & 0xFF) + ((float)iter / (float)MAX_ITER)
				* ((colour_1 >> 8 & 0xFF) - (colour_2 >> 8 & 0xFF)));
		b = (int)((colour_2 & 0xFF) + ((float)iter / (float)MAX_ITER)
				* ((colour_1 & 0xFF) - (colour_2 & 0xFF)));
		f->colour = r << 16 | g << 8 | b;
		img_pix_put(&data->img, f->pixel.x, f->pixel.y, f->colour);
	}
	else
		img_pix_put(&data->img, f->pixel.x, f->pixel.y, colour_1);
	return (0);
}
