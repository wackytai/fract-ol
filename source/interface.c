/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:16:50 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/21 14:37:40 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
		(W_HEIGHT / 3) + (2 * offset_y), 0xFFFFFF, "Julia");
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
