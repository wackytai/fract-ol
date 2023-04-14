/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:45:35 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/14 15:40:57 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int ft_mandelbrot(t_data *data, t_fractal *fractal)
{
    int     iter;
    double  x;
    double  y;

    iter = 0;
    x = fractal->x;
    y = fractal->y;
    while (iter < MAX_ITER && (fractal->x * fractal->x + fractal->y * fractal->y) <= 4)
    {
        fractal->x = (fractal->x * fractal->x) + (fractal->y * fractal->y) + x;
        fractal->y = (2 * fractal->x * fractal->y) + y;
        iter++;
    }
    if (iter == MAX_ITER)
        return(0xFF0000);
    return (0);
}

int ft_julia_static(t_data *data, t_fractal *fractal)
{
    return (0);
}
