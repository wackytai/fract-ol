/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:59:57 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/05 15:00:48 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_colour(t_data *data, int iter)
{
	int	colour_1;
	int	colour_2;
	int	r;
	int	g;
	int	b;

	colour_1 = data->f->col_set.colour_1;
	colour_2 = data->f->col_set.colour_2;
	if (iter < MAX_ITER)
	{
		r = (int)((colour_2 >> 16 & 0xFF) + ((float)iter / (float)MAX_ITER)
				* ((colour_1 >> 16 & 0xFF) - (colour_2 >> 16 & 0xFF)));
		g = (int)((colour_2 >> 8 & 0xFF) + ((float)iter / (float)MAX_ITER)
				* ((colour_1 >> 8 & 0xFF) - (colour_2 >> 8 & 0xFF)));
		b = (int)((colour_2 & 0xFF) + ((float)iter / (float)MAX_ITER)
				* ((colour_1 & 0xFF) - (colour_2 & 0xFF)));
		data->f->colour = r << 16 | g << 8 | b;
		img_pix_put(&data->img, data->f->pixel.x, data->f->pixel.y,
			data->f->colour);
	}
	else
		img_pix_put(&data->img, data->f->pixel.x, data->f->pixel.y, colour_1);
	return (0);
}

void	set_palettes(int set, t_palette *plt)
{
	if (set == 0)
	{
		plt->colour_1 = 0xB431F4;
		plt->colour_2 = 0xCC37C2;
		plt->colour_3 = 0xFF24A4;
		plt->colour_4 = 0xACE900;
		plt->colour_5 = 0x46E4BC;
	}
	else if (set == 1)
	{
		plt->colour_1 = 0xCFF09E;
		plt->colour_2 = 0xA8DBA8;
		plt->colour_3 = 0x79BD9A;
		plt->colour_4 = 0x3B8686;
		plt->colour_5 = 0x0B486B;
	}
	else if (set == 2)
	{
		plt->colour_1 = 0x343838;
		plt->colour_2 = 0x005F6B;
		plt->colour_3 = 0x008C9E;
		plt->colour_4 = 0x00B4CC;
		plt->colour_5 = 0x00DFFC;
	}
	else if (set == 3)
	{
		plt->colour_1 = 0x1C0113;
		plt->colour_2 = 0x6B0103;
		plt->colour_3 = 0xA30006;
		plt->colour_4 = 0xC21A01;
		plt->colour_5 = 0xF03C02;
	}
	else if (set == 4)
	{
		plt->colour_1 = 0x69D2E7;
		plt->colour_2 = 0xA7DBD8;
		plt->colour_3 = 0xE0E4CC;
		plt->colour_4 = 0xF38630;
		plt->colour_5 = 0xFA6900;
	}
	return ;
}
