/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:49:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/19 16:02:36 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	check_input(char **argv, t_data *data, t_fractal *fractal);

int	initialize(int argc, char **argv, t_data *data, t_fractal *fractal)
{
	int	x;

	x = -1;
	if (argc >= 1)
	{
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
				&data->img.line_len, &data->img.endian);
		/* data->img.img_map = (int **)ft_calloc(sizeof(int *), W_HEIGHT + 1);
		while (++x < W_HEIGHT)
			data->img.img_map[x] = (int *)ft_calloc(sizeof(int), W_WIDTH); */
	}
	if (argc == 1)
	{
		printf("Usage Error: No fractal selected\n");
		render_menu(data);
	}
	else if (argc == 2)
	{
		check_input(argv, data, fractal);
		set_struct(fractal);
		if (fractal->flag == 1)
			ft_mandelbrot(data, fractal);
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

void	set_struct(t_fractal *fractal)
{
	fractal->pixel.x = 0;
	fractal->pixel.y = 0;
	fractal->f_center.x = W_WIDTH / 2;
	fractal->f_center.y = W_HEIGHT / 2;
	fractal->max.x = 2;
	fractal->max.y = 2;
	fractal->min.x = -1.5;
	fractal->min.y = 0;
	fractal->offset.x = 0;
	fractal->offset.y = 0;
	fractal->zoom = 1;
	fractal->colour = 0xFFFFFF;
	return ;
}
