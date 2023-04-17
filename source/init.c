/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:49:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/17 16:58:12 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	check_input(char **argv, t_data *data, t_fractal *fractal);

int	initialize(int argc, char **argv, t_data *data, t_fractal *fractal)
{
	if (argc >= 1)
	{
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
				&data->img.line_len, &data->img.endian);
	}
	if (argc == 1)
	{
		printf("Usage Error: No fractal selected\n");
		render_menu(data);
	}
	else if (argc == 2)
	{
		check_input(argv, data, fractal);
	}
	return (0);
}

void	check_input(char **argv, t_data *data, t_fractal *fractal)
{
	if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0)
	{
		fractal->flag = 1;
		printf("Mandelbrot set selected %i\n", fractal->flag);
	}
	else if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
	{
		fractal->flag = 2;
		printf("Fixed Julia set selected %i\n", fractal->flag);
	}
	else
	{
		printf("Usage Error: Invalid fractal selected!\n");
		render_menu(data);
	}
	return ;
}
