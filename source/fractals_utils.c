/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:17 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/21 11:55:51 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	iterate_complex(t_data *data, t_fractal *f)
{
	int		iter;
	double	temp;

	iter = -1;
	temp = 0;
	while (++iter < MAX_ITER && (f->z.x * f->z.x) + (f->z.y * f->z.y) <= 4)
	{
		temp = (f->z.x * f->z.x) - (f->z.y * f->z.y) + f->c.x;
		f->z.y = (2 * f->z.x * f->z.y) + f->c.y;
		f->z.x = temp;
	}
	get_colour(data, f, iter);
	return ;
}
