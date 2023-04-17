/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:25 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/17 16:58:05 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
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
#  define MAX_ITER 15
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

//are the max and min members really necessary if I'm already checking x^2 + y^2 <= 4?
typedef struct s_fractal
{
	double		x;
	double		y;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	z;
	int			zoom;
	int			flag;
}	t_fractal;

/*main.c*/
int			main(int argc, char **argv);
int			handle_no_event(void *data);
int			handle_keyrelease(int keysym, void *data);
int			handle_keypress(int keysym, t_data *data);
int			handle_mouse_input(int button, t_data *data);

/*render.c*/
void		img_pix_put(t_img *img, int x, int y, int colour);
int			render_rect(t_img *img, t_rect rect);
void		render_background(t_img *img, int colour);
int			fill_image(t_data *data);
int			render(t_data *data);

/*fractals.c*/
int			ft_mandelbrot(t_data *data, t_fractal *fractal);
int			ft_julia_static(t_data *data, t_fractal *fractal);

/*interface.c*/
void		update_zoom(t_fractal *fractal, int flag);
void		pan_image(t_data *data, int flag);
int			create_body_commands(t_data *data, int offset_x, int offset_y);
int			create_menu(t_data *data);
int			render_menu(t_data *data);

/*init.c*/
int			initialize(int argc, char **argv, t_data *data, t_fractal *fractal);
void		check_input(char **argv, t_data *data, t_fractal *fractal);

/*clean.c*/
int			destroy_all(t_data *data);
int			close_window(t_data *data);

#endif