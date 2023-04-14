/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:25 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/14 13:50:27 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <math.h>

# ifndef W_WIDTH
#  define W_WIDTH 1920
# endif

# ifndef W_HEIGHT
#  define W_HEIGHT 1080
# endif

# ifndef MAX_ITER
#  define MAX_ITER 50
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

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	z;
	int		zoom;
}	t_fractal;

/*main.c*/
int		main(int argc, char **argv);
int		handle_no_event(void *data);
int		handle_keyrelease(int keysym, void *data);

/*render.c*/
void	img_pix_put(t_img *img, int x, int y, int colour);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int colour);
int		render(t_data *data);

/*fractals.c*/
int 	ft_mandelbrot(t_data *data, t_fractal *fractal);

/*interface.c*/
void	update_zoom(void);
int		create_menu(t_data *data);

/*clean.c*/
int		destroy_all(t_data *data);
int		close_window(t_data *data);

#endif