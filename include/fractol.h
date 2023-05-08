/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:25 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/05/08 13:17:47 by tlemos-m         ###   ########.fr       */
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
# define MAX_ITER 40

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

typedef struct s_colours
{
	int	colour_1;
	int	colour_2;
	int	colour_3;
	int	colour_4;
	int	colour_5;
}	t_palette;

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
	t_palette	col_set;
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
int			ft_burning_ship(t_data *data);

/*fractals_utils.c*/
void		iterate_complex(t_data *data);
void		set_mdb_range(t_fractal *fractal);
void		set_julia_range(t_fractal *fractal, int flag);
void		set_ship_range(t_fractal *fractal);
void		iterate_abs(t_data *data);

/*render_utils.c*/
void		update_zoom(t_data *data, int x, int y);
void		pan_image(t_data *data, int flag);
void		update_colour_set(t_data *data, int flag);

/*interface.c*/
int			create_body_commands(t_data *data, int offset_x, int offset_y);
int			create_menu(t_data *data);
int			render_menu(t_data *data);

/*init.c*/
int			initialize(int argc, char **argv, t_data *data, t_fractal *fractal);
void		error_management(t_data *data, int error);
void		check_input(char **argv, t_data *data);
void		set_data(t_data *data);
void		choose_fractal(t_data *data);

/*clean.c*/
int			destroy_all(t_data *data);
int			close_window(t_data *data);
int			update_screen(t_data *data);

/*colours.c*/
int			get_colour(t_data *data, int iter);
int			colour_lerp(int start, int end, double gradient);
void		set_palettes(int set, t_palette *plt);
void		set_palettes_2(int set, t_palette *plt);


/*ft_atof.c*/
double		ft_atof(char *str);
int			skip_char(char **str, int flag);

#endif