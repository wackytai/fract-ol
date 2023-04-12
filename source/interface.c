/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:16:50 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/12 15:58:32 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../mlx_linux/mlx.h"

//update_zoom must receive the struct which has the zoom variable as a member
//replace int zoom for the struct member when struct is ready
//don't forget to make zoom relative to mouse position
void	update_zoom(void)
{
	int	zoom;

	zoom = 0;
	if (zoom < 1)
		zoom = 1;
	else
		zoom += 1;
}

int	create_menu(t_data *data)
{
	render_background(&data->img, 0x808080);
	mlx_string_put(data->mlx_ptr, data->win_ptr, W_WIDTH / 2,
		W_HEIGHT / 4, 0xFFFFFF, "Help Center");
	mlx_string_put(data->mlx_ptr, data->win_ptr, W_WIDTH / 3,
		(W_HEIGHT / 3) * 2, 0xFFFFFF,
		"Fractals\nAvailable:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (W_WIDTH / 3) * 2,
		(W_HEIGHT / 3) * 2, 0xFFFFFF, "Mandelbrot\nJulia\nCantor Set");
	mlx_string_put(data->mlx_ptr, data->win_ptr, W_WIDTH / 3,
		W_HEIGHT - W_HEIGHT / 4, 0xFFFFFF, "Zoom:\nPan:\nColour Range Shift:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (W_WIDTH / 3) * 2,
		W_HEIGHT - W_HEIGHT / 4, 0xFFFFFF, "Mouse Scroll\nArrows\nMouse Move");
	return (0);
}
