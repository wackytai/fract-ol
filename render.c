/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:18:07 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/12 11:45:25 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./mlx_linux/mlx.h"

void	img_pix_put(t_img *img, int x, int y, int colour)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (colour >> i) & 0xFF;
		else
			*pixel++ = (colour >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.colour);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
			img_pix_put(img, j++, i, colour);
		++i;
	}
}

int	render(t_data *data)
{
	int	x;
	int	y;

	x = W_WIDTH;
	//y = 20;
	y = W_HEIGHT;
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, 0x000000);
/* 	render_rect(&data->img, (t_rect){0, 0, x, y, 0xFFFFFF});
	render_rect(&data->img, (t_rect){0, y * 2, x / 3, y, 0xFFFFFF});
	render_rect(&data->img, (t_rect){x - (x / 3), y * 2, x / 3, 20, 0xFFFFFF});
	render_rect(&data->img, (t_rect){0, y * 4, x / 9, y, 0xFFFFFF});
	render_rect(&data->img, (t_rect){x / 9 + x / 9, y * 4, x / 9, y, 0xFFFFFF});
	render_rect(&data->img, (t_rect){x - x / 3, y * 4, x / 9, y, 0xFFFFFF});
	render_rect(&data->img, (t_rect){x - (x / 9), y * 4, x / 9, 20, 0xFFFFFF}); */
	draw_circle(&data->img, (t_rect){x, y, x / 4, y / 4, 0xFF});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	draw_circle(t_img *img, t_rect circle)
{
	int	i;
	int	j;
	int	radius_2;
	int	f_x;
	int	f_y;

	i = circle.y;
	j = 0;
	radius_2 = circle.width * circle.width;
	while (i < (circle.height * 2) + circle.y)
	{
		f_y = circle.y - i;
		j = circle.x;
		while (j < (circle.width * 2) + circle.x)
		{
			f_x = j - circle.x;
			if ((f_x * f_x) + ((i - circle.y) * (i - circle.y)) <= radius_2)
				img_pix_put(img, j / 2, i / 2, circle.colour);
			if (((circle.x - j) * (circle.x - j)) + (f_y * f_y) <= radius_2)
				img_pix_put(img, (circle.x - j / 2), i / 2, circle.colour);	
			if ((f_x * f_x) + (f_y * f_y) <= radius_2)
				img_pix_put(img, j / 2, (circle.y - i / 2), circle.colour);
			if (((circle.x - j) * (circle.x - j)) + (f_y * f_y) <= radius_2)
				img_pix_put(img, (circle.x - j / 2), (circle.y - i/ 2), circle.colour);
			j++;
		}
		i++;
	}
	return (0);
}
