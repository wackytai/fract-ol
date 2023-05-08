/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:49:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/08 13:07:55 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_management(t_data *data, int error);
void	check_input(char **argv, t_data *data);
void	set_data(t_data *data);
void	choose_fractal(t_data *data);

int	initialize(int argc, char **argv, t_data *data, t_fractal *fractal)
{
	if (argc >= 1)
	{
		data->f = fractal;
		set_data(data);
	}
	if (argc == 1)
		error_management(data, 1);
	else if (argc == 2)
		check_input(argv, data);
	else if (argc == 4 && ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
	{
		data->flag = 3;
		printf("Customized Julia set selected\n");
		fractal->c.x = ft_atof(argv[2]);
		fractal->c.y = ft_atof(argv[3]);
		if (fractal->c.x < -2.0 || fractal->c.x > 2.0 || fractal->c.y < -2.0
			|| fractal->c.y > 2.0)
			error_management(data, 2);
		else
			choose_fractal(data);
	}
	else
		error_management(data, 3);
	return (0);
}

void	error_management(t_data *data, int error)
{
	if (error == 1)
		printf("Usage error: no fractal selected\n");
	else if (error == 2)
		printf("Usage error: invalid arguments for Julia\n");
	else if (error == 3)
		printf("Usage error: wrong arguments\n");
	render_menu(data);
	return ;
}

void	check_input(char **argv, t_data *data)
{
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
	{
		data->flag = 1;
		printf("Mandelbrot set selected\n");
		choose_fractal(data);
	}
	else if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
	{
		data->flag = 2;
		printf("Static Julia set selected\n");
		choose_fractal(data);
	}
	else if (ft_strncmp(argv[1], "burning_ship", ft_strlen(argv[1])) == 0)
	{
		data->flag = 4;
		printf("Burning Ship set selected\n");
		choose_fractal(data);
	}
	else
	{
		printf("Usage Error: Invalid fractal selected!\n");
		render_menu(data);
	}
	return ;
}

void	set_data(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->f->zoom = 1;
	data->f->offset.x = 0;
	data->f->offset.y = 0;
	data->f->c_palette = 0;
	set_palettes(data->f->c_palette, &data->f->col_set);
	return ;
}

void	choose_fractal(t_data *data)
{
	data->f->colour = 0xFFFFFF;
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
	else if (data->flag == 4)
	{
		set_ship_range(data->f);
		ft_burning_ship(data);
	}
	return ;
}
