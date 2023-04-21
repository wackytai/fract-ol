/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:59:57 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/21 11:26:26 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_colour(t_data *data, t_fractal *f, int iter)
{
	int	colour_1;
	int	colour_2;

	colour_1 = 0x00807F;
	colour_2 = 0xCC4D01;
	if (iter < MAX_ITER - 1)
		img_pix_put(&data->img, f->pixel.x, f->pixel.y, colour_1);
	else
		img_pix_put(&data->img, f->pixel.x, f->pixel.y, colour_2);
	return (0);
}
