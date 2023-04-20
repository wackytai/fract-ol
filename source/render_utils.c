/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:52:14 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/20 14:24:11 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//update_zoom must receive the struct which has the zoom variable as a member
//replace int zoom for the struct member when struct is ready
//don't forget to make zoom relative to mouse position
//update screen after panning image!
void	update_zoom(t_fractal *fractal, int flag, int x, int y)
{
	if (flag > 0)
		fractal->zoom *= 1.15;
	else if (flag < 0)
	{
		if (fractal->zoom < 1)
			fractal->zoom = 1;
		else
			fractal->zoom *= 0.85;
	}
}

void	pan_image(t_data *data, int flag, int x, int y)
{
	if (flag == 0 && data)
		printf("Pan 1.15 right\n");
	else if (flag == 1)
		printf("Pan 1.15 left\n");
	else if (flag == 2)
		printf("Pan 1.15 up\n");
	else if (flag == 3)
		printf("Pan 1.15 down\n");
	return ;
}
