/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:25 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/04/12 13:10:35 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
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

/*main.c*/
int		main(void);
int		handle_no_event(void *data);
int		handle_keyrelease(int keysym, void *data);

/*render.c*/
void	img_pix_put(t_img *img, int x, int y, int colour);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int colour);
int		render(t_data *data);

/*clean.c*/
int		destroy_all(t_data *data);
int		close_window(t_data *data);

#endif