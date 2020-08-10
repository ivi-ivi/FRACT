/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 02:16:02 by mcrissy           #+#    #+#             */
/*   Updated: 2020/08/07 17:40:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../Libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 100
# define MAX_ITER_JULIA 50
# define THREAD_NUM 10
# define MAN 0
# define JUL 1
# define HEA 2
# define CM 3

/*
** # define COL_1 0x00FF00
** # define COL_2 0xFFFF00
** # define COL_3 0x00FA9A
** # define COL_4 0xFF00FF
** # define COL_5 0xFFFF99
** # define COL_6 0x00FFFF
*/

# define COL_2 0x1F104F
# define COL_1 0x0000CD
# define COL_3 0x8B0000
# define COL_4 0xFF4500
# define COL_5 0xFFD700
# define COL_6 0xF0E68C

typedef struct	s_fractol
{
	void		*mlx;
	void		*window;
	void		*pic;
	void		*pic_ptr;
	int			en;
	int			width;
	int			max;
	int			sl;
	int			bpp;
	int			fractal;
	int			color;
	int			julia_mouse;
	int			x;
	int			y;
	int			iter;
	int			y_max;
	double		zoom;
	double		x2;
	double		y2;
	double		c_re;
	double		c_i;
	double		z_re;
	double		z_i;
	double		tmp;
}				t_fractol;

int				key_hook(int keycode, t_fractol *f);
void			ft_zoom(int x, int y, t_fractol *f);
void			ft_zoom_minus(int x, int y, t_fractol *f);
int				mouse_hook(int mousecode, int x, int y, t_fractol *f);
void			mlx_hooks_loop(t_fractol *f);
void			init_man(t_fractol *f);
void			mandelbrot(t_fractol *f);
void			*which_fract(t_fractol *f);
void			*fractal_start(void *mas);
void			pthread(t_fractol *f);
int				color(int iter, t_fractol *f);
int				color_2(int iter, t_fractol *f);
int				julia_mouse_move(int x, int y, t_fractol *f);
void			init_jul(t_fractol *f);
void			julia(t_fractol *f);
void			init_heart(t_fractol *f);
void			heart(t_fractol *f);
void			init_cel_man(t_fractol *f);
void			celtic_mandelbrot(t_fractol *f);
int				ft_close(void);
void			put_pxl_to_pic(t_fractol *f, int x, int y, int color);
void			create_fractal(t_fractol *f);
void			begin(t_fractol *f);
void			mlx_windowdow(t_fractol *f);
int				cmp_fractal(char *str, t_fractol *f);
#endif
