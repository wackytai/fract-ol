/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:52:14 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/24 14:15:21 by tlemos-m         ###   ########.fr       */
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
			data->f.zoom *= 1.15;
		else if (data->f.z_flag < 0)
			data->f.zoom *= 0.85;
	}
	update_screen(data);
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
