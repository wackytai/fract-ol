/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:44:06 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/14 15:21:50 by tlemos-m         ###   ########.fr       */
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
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_fractal	fractal;

	if (initialize(&data) > 0)
	{
		destroy_all(&data);
		free(data.mlx_ptr);
		return (1);	
	}
	/* data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W_WIDTH, W_HEIGHT, "fract-ol");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	if (argc == 1 && argv)
		create_menu(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		&data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &close_window,
		&data);
	mlx_loop(data.mlx_ptr); */
	if (argc == 2)
	{
		if (ft_strncmp(argv[1]), "Mandelbrot", ft_strlen(argv[1]) == 0)
		{
			set_initial_fractal(&fractal, 0);
			ft_mandelbrot(&data, &fractal);
		}
		else if (ft_strncmp(argv[1]), "Julia", ft_strlen(argv[1]) == 0)
		{
			set_initial_fractal(&fractal, 1);
		}
	}
	destroy_all(&data);
	free(data.mlx_ptr);
}
