/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:49:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/14 15:17:38 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int initialize(t_data *data)
{
    data.mlx_ptr = mlx_init();
    if (!data.mlx.ptr)
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
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &close_window, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}

void    set_initial_fractal(t_fractal *fractal, int flag)
{
        fractal->x = 0;
        fractal->y = 0;
        fractal->min.re = -2;
        fractal->min.im = -2;
        fractal->max.re = 2;
        fractal->max.im = 2;
        fractal->zoom = 1;
    if (flag == 0)
    {
        fractal->c.re =
        fractal->c.im =
        fractal->z.re =
        fractal->z.im =
    }
}
