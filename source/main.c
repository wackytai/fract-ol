/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:44:06 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/21 15:33:41 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	handle_no_event(void *data)
{
	if (data)
		return (0);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	if (data)
	{
		if (keysym == XK_Escape)
			close_window(data);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		pan_image(&data->f, -1);
	if (keysym == XK_Right)
		pan_image(&data->f, 1);
	if (keysym == XK_Up)
		pan_image(&data->f, 2);
	if (keysym == XK_Down)
		pan_image(&data->f, -2);
	return (0);
}

int	handle_mouse_input(int button, int x, int y, t_data *data)
{
	if (data->f.zoom == 0)
		data->f.zoom = 1;
	printf("zoom: %f\n", data->f.zoom);
	if (button == 4)
	{
		data->f.z_flag = 1;
		update_zoom(data, x, y);
		update_screen(data);
	}
	if (button == 5)
	{
		data->f.z_flag = -1;
		update_zoom(data, x, y);
	}
	if (button == 1 && (x || y))
	{
		data->f.z_flag = 2;
	}
	if (button == 3)
	{
		data->f.z_flag = -2;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_fractal	fractal;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W_WIDTH, W_HEIGHT,
			"fract-ol");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (1);
	}
	initialize(argc, argv, &data, &fractal);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouse_input, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		&data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&close_window, &data);
	mlx_loop(data.mlx_ptr);
	destroy_all(&data);
	free(data.mlx_ptr);
	return (0);
}
