/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:59:57 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/24 15:37:47 by tlemos-m         ###   ########.fr       */
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

	colour_1 = 0x000000;
	colour_2 = 0x000000;
	colour_1 = set_colour(f, colour_1, 1);
	colour_2 = set_colour(f, colour_2, 2);
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

int	set_colour(t_fractal *f, int colour, int flag)
{
	if (flag == 1)
	{
		if (f->c_palette == 0)
			colour = 0xFFE863;
		else if (f->c_palette == 1)
			colour = 0xADE72F;
		else if (f->c_palette == 2)
			colour = 0xFF8F56;
		else if (f->c_palette == 3)
			colour = 0xf24d4f;
		else if (f->c_palette == 4)
			colour = 0xfce611;
	}
	else
	{
		if (f->c_palette == 0)
			colour = 0x47297B;
		else if (f->c_palette == 1)
			colour = 0xFB68FF;
		else if (f->c_palette == 2)
			colour = 0x0960BD;
		else if (f->c_palette == 3)
			colour = 0x4b211f;
		else if (f->c_palette == 4)
			colour = 0xeb1d28;
	}
	return (colour);
}
