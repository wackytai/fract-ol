/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:52:14 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/08 10:02:13 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	update_zoom(t_data *data, int x, int y)
{
	if (x <= W_WIDTH && y <= W_HEIGHT)
	{
		if (data->f->z_flag > 0)
		{
			data->f->zoom *= 1.05;
			data->f->offset.x -= (((double)x - (W_WIDTH / 2)) / W_WIDTH)
				* data->f->zoom;
			data->f->offset.y -= (((double)y - (W_HEIGHT / 2)) / W_HEIGHT)
				* data->f->zoom;
		}
		else if (data->f->z_flag < 0)
		{
			data->f->zoom *= 0.95;
			data->f->offset.x += (((double)x - (W_WIDTH / 2)) / W_WIDTH)
				* data->f->zoom;
			data->f->offset.y += (((double)y - (W_HEIGHT / 2)) / W_HEIGHT)
				* data->f->zoom;
		}
		update_screen(data);
	}
	return ;
}

void	pan_image(t_data *data, int flag)
{
	if (flag == 1)
		data->f->offset.x += 0.15 * data->f->zoom;
	else if (flag == -1)
		data->f->offset.x -= 0.15 * data->f->zoom;
	else if (flag == 2)
		data->f->offset.y -= 0.15 * data->f->zoom;
	else if (flag == -2)
		data->f->offset.y += 0.15 * data->f->zoom;
	update_screen(data);
	return ;
}
