/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:25 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/03 15:08:40 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef W_WIDTH
#  define W_WIDTH 1920
# endif

# ifndef W_HEIGHT
#  define W_HEIGHT 1080
# endif

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

/*main.c*/
int	main(void);
int	handle_input(int keysym, t_data *data);
int	handle_no_event(void *data);

#endif