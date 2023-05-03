/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:02:19 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/03 13:22:59 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_atof(char *str)
{
	int		i;
	double	res;
	int		s;
	double	div;

	i = 0;
	res = 0;
	s = 1;
	div = 0.1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if (str[i] > 47 && str[i] < 51)
	{
		res = (res * 10.0) + (str[i] - '0');
		i++;
	}
	else
		return (3);
	if (str[i] == '.')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		res = res + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (res * s);
}
