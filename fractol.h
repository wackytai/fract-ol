/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:25 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/05 16:59:06 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# ifndef W_WIDTH
#  define W_WIDTH 1920
# endif

# ifndef W_HEIGHT
#  define W_HEIGHT 1080
# endif

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	colour;
}	t_rect;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

/*main.c*/
int		main(void);
//int		handle_input(int keysym, t_data *data);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, void *data);

/*render.c*/
void	img_pix_put(t_img *img, int x, int y, int colour);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int colour);
int		render(t_data *data);

/*fractals.c*/
void	ft_cantor(t_data *data);

#endif