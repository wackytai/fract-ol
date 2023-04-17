/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:16:50 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/17 16:56:21 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//update_zoom must receive the struct which has the zoom variable as a member
//replace int zoom for the struct member when struct is ready
//don't forget to make zoom relative to mouse position
//update screen after panning image!
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

int	create_body_commands(t_data *data, int offset_x, int offset_y)
{
	mlx_set_font(data->mlx_ptr, data->win_ptr, "10x20");
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

int	create_menu(t_data *data)
{
	int	offset_x;
	int	offset_y;

	offset_x = 72;
	offset_y = 24;
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
	create_body_commands(data, offset_x, offset_y);
	return (0);
}

int	render_menu(t_data *data)
{
	fill_image(data);
	render(data);
	create_menu(data);
	return (0);
}
