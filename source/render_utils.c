/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:52:14 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/03 11:47:18 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//don't forget to make zoom relative to mouse position
void	update_zoom(t_data *data, int x, int y)
{
	if (x <= W_WIDTH && y <= W_HEIGHT)
	{
		if (data->f.z_flag > 0)
			data->f.zoom *= 1.15;
		else if (data->f.z_flag < 0)
			data->f.zoom *= 0.85;
		update_screen(data);
	}
	return ;
}

void	pan_image(t_data *data, int flag)
{
	if (flag == 1)
		data->f.offset.x += 0.5 * data->f.zoom;
	else if (flag == -1)
		data->f.offset.x -= 0.5 * data->f.zoom;
	else if (flag == 2)
		data->f.offset.y -= 0.5 * data->f.zoom;
	else if (flag == -2)
		data->f.offset.y += 0.5 * data->f.zoom;
	update_screen(data);
	return ;
}
