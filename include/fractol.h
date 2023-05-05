/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:25 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/05 09:39:46 by tlemos-m         ###   ########.fr       */
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

# define W_WIDTH 1290
# define W_HEIGHT 720
# define MAX_ITER 50

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

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal
{
	t_complex	pixel;
	t_complex	f_center;
	t_complex	offset;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	z;
	double		zoom;
	int			z_flag;
	int			colour;
	int			c_palette;
}	t_fractal;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_fractal	*f;
	int			flag;
}	t_data;

/*main.c*/
int			main(int argc, char **argv);
int			handle_no_event(void *data);
int			handle_keyrelease(int keysym, void *data);
int			handle_keypress(int keysym, t_data *data);
int			handle_mouse_input(int button, int x, int y, t_data *data);

/*render.c*/
void		img_pix_put(t_img *img, int x, int y, int colour);
int			render_rect(t_img *img, t_rect rect);
void		render_background(t_img *img, int colour);
int			fill_image(t_data *data);
int			render(t_data *data);

/*fractals.c*/
int			ft_mandelbrot(t_data *data);
int			ft_julia_static(t_data *data);

/*fractals_utils.c*/
void		iterate_complex(t_data *data);
void		set_mdb_range(t_fractal *fractal);
void		set_julia_range(t_fractal *fractal, int flag);

/*render_utils.c*/
void		update_zoom(t_data *data, int x, int y);
void		pan_image(t_data *data, int flag);
void		toggle_input(t_fractal *fractal);

/*interface.c*/
int			create_body_commands(t_data *data, int offset_x, int offset_y);
int			create_menu(t_data *data);
int			render_menu(t_data *data);

/*init.c*/
int			initialize(int argc, char **argv, t_data *data, t_fractal *fractal);
void		check_input(char **argv, t_data *data);
void		set_struct(t_fractal *fractal);
void		choose_fractal(t_data *data);

/*clean.c*/
int			destroy_all(t_data *data);
int			close_window(t_data *data);
int			update_screen(t_data *data);

/*colours.c*/
int			get_colour(t_data *data, int iter);
int			set_colour(t_fractal *f, int colour, int flag);

/*ft_atof.c*/
double		ft_atof(char *str);

#endif