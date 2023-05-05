/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:02:19 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/05 13:08:40 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		skip_char(char **str, int flag);

double	ft_atof(char *str)
{
	double	res;
	int		s;
	double	div;

	res = 0;
	div = 0.1;
	s = skip_char(&str, 0);
	if (*str > 47 && *str < 51)
	{
		res = (res * 10.0) + (*str - '0');
		str++;
	}
	else
		res = 3;
	skip_char(&str, 1);
	while (*str > 47 && *str < 58)
	{
		res = res + ((*str - '0') * div);
		div *= 0.1;
		str++;
	}
	if (*str != '\0')
		res = 3;
	return (res * s);
}

int	skip_char(char **str, int flag)
{
	if (flag == 0)
	{
		if (*str[0] == '-' || *str[0] == '+')
		{
			if (*str[0] == '-')
			{
				(*str)++;
				return (-1);
			}
			(*str)++;
		}
		return (1);
	}
	if (flag == 1)
	{
		if (*str[0] == '.')
			(*str)++;
		return (1);
	}
	return (1);
}
