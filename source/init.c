/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:49:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/05 09:43:16 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_struct(t_fractal *fractal);
void	check_input(char **argv, t_data *data);
void	choose_fractal(t_data *data);

int	initialize(int argc, char **argv, t_data *data, t_fractal *fractal)
{
	if (argc >= 1)
	{
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
				&data->img.line_len, &data->img.endian);
		data->f = fractal;
		data->f->zoom = 1;
		data->f->offset.x = 0;
		data->f->offset.y = 0;
		data->f->c_palette = 0;
	}
	if (argc == 1)
	{
		printf("Usage Error: No fractal selected\n");
		render_menu(data);
	}
	else if (argc == 2)
		check_input(argv, data);
	else if (argc == 4 && ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
	{
		data->flag = 3;
		printf("Dynamic Julia %i\n", data->flag);
		fractal->c.x = ft_atof(argv[2]);
		fractal->c.y = ft_atof(argv[3]);
		if (fractal->c.x < -2.0 || fractal->c.x > 2.0 || fractal->c.y < -2.0 || fractal->c.y > 2.0)
		{
			printf("Usage Error: Arguments out of range\n");
			render_menu(data);
		}
	}
	return (0);
}

void	check_input(char **argv, t_data *data)
{
	set_struct(data->f);
	if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0)
	{
		data->flag = 1;
		printf("Mandelbrot set selected %i\n", data->flag);
		choose_fractal(data);
	}
	else if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
	{
		data->flag = 2;
		printf("Static Julia set selected %i\n", data->flag);
		choose_fractal(data);
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
	fractal->f_center.x = -0.75 * fractal->zoom;
	fractal->f_center.y = -1 * fractal->zoom;
	fractal->max.x = 2 * fractal->zoom;
	fractal->max.y = 2 * fractal->zoom;
	fractal->min.x = -1.5 * fractal->zoom;
	fractal->min.y = 0 * fractal->zoom;
	fractal->z.x = 0;
	fractal->z.y = 0;
	fractal->colour = 0xFFFFFF;
	return ;
}

void	choose_fractal(t_data *data)
{
	if (data->flag == 1)
	{
		set_mdb_range(data->f);
		ft_mandelbrot(data);
	}
	else if (data->flag == 2 || data->flag == 3)
	{
		set_julia_range(data->f, data->flag);
		ft_julia_static(data);
	}
	return ;
}
