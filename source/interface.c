/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:16:50 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/14 15:44:52 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//update_zoom must receive the struct which has the zoom variable as a member
//replace int zoom for the struct member when struct is ready
//don't forget to make zoom relative to mouse position
void	update_zoom(t_fractal *fractal, int flag)
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

void	pan_image(t_data *data, int flag)
{
	if (flag == 0)
	{
		//pan 1.15 right
	}
	else if (flag == 1)
	{
		//pan 1.15 left
	}
	else if (flag == 2)
	{
		//pan 1.15 up
	}
	else if (flag == 3)
	{
		//pan 1.15 down
	}
	//update screen
}

int	create_menu(t_data *data)
{
	int	offset_x;
	int	offset_y;

	offset_x = 72;
	offset_y = 20;
	render(data);
	mlx_set_font(data->mlx_ptr, data->win_ptr, "12x24");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (W_WIDTH / 2) - offset_x,
		W_HEIGHT / 4, 0xFFFFFF, "Help Center");
	mlx_set_font(data->mlx_ptr, data->win_ptr, "10x20");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (W_WIDTH / 3) - offset_x,
		W_HEIGHT / 3, 0xFFFFFF,
		"Fractals Available:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, ((W_WIDTH / 3) * 2) - offset_x,
		W_HEIGHT / 3, 0xFFFFFF, "Mandelbrot");
	mlx_string_put(data->mlx_ptr, data->win_ptr, ((W_WIDTH / 3) * 2) - offset_x,
		(W_HEIGHT / 3) + offset_y, 0xFFFFFF, "Julia");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (W_WIDTH / 3 - offset_x),
		(W_HEIGHT / 3) * 3 / 2, 0xFFFFFF, "Zoom:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, ((W_WIDTH / 3) * 2) - offset_x,
		(W_HEIGHT / 3) * 3 / 2, 0xFFFFFF, "Mouse Scroll");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (W_WIDTH / 3 - offset_x),
		((W_HEIGHT / 3) * 3 / 2) + (offset_y * 2), 0xFFFFFF, "Pan:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, ((W_WIDTH / 3) * 2) - offset_x,
		((W_HEIGHT / 3) * 3 / 2) + (offset_y * 2), 0xFFFFFF, "Arrow Keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (W_WIDTH / 3 - offset_x),
		((W_HEIGHT / 3) * 3 / 2) + (offset_y * 4), 0xFFFFFF, "Shift Colours:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, ((W_WIDTH / 3) * 2) - offset_x,
		((W_HEIGHT / 3) * 3 / 2) + (offset_y * 4), 0xFFFFFF, "Mouse Movement");
	return (0);
}
