/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:52:14 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/21 14:11:31 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//update_zoom must receive the struct which has the zoom variable as a member
//replace int zoom for the struct member when struct is ready
//don't forget to make zoom relative to mouse position
//update screen after panning image!
void	update_zoom(t_data *data, int x, int y)
{
	if (x || y)
	{
		if (data->f.z_flag > 0)
		{
			data->f.zoom *= 1.15;
		}
		else if (data->f.z_flag < 0)
		{
			if (data->f.zoom <= 1)
				data->f.zoom = 1;
			else
				data->f.zoom *= 0.85;
		}
	}
	printf("zoom: %f\n", data->f.zoom);
}

void	pan_image(t_fractal *fractal, int flag)
{
	if (flag == 1)
		fractal->offset.x += 1.15;
	else if (flag == -1)
		fractal->offset.x -= 1.15;
	else if (flag == 2)
		fractal->offset.y += 1.15;
	else if (flag == -2)
		fractal->offset.y -= 1.15;
	return ;
}
