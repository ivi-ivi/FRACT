/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 02:16:35 by mcrissy           #+#    #+#             */
/*   Updated: 2020/08/10 15:19:50 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_mouse_move(int x, int y, t_fractol *f)
{
	if (f->fractal == JUL && f->julia_mouse == 1)
	{
		f->c_re = x * 3;
		f->c_i = 2 * y - HEIGHT;
		create_fractal(f);
	}
	return (0);
}

int		key_hook(int keycode, t_fractol *f)
{
	if (keycode == 35)
		f->julia_mouse = !f->julia_mouse;
	if (keycode == 53)
		exit(1);
	else if (keycode == 123)
		f->x2 -= 10 / f->zoom;
	else if (keycode == 124)
		f->x2 += 10 / f->zoom;
	else if (keycode == 125)
		f->y2 += 10 / f->zoom;
	else if (keycode == 126)
		f->y2 -= 10 / f->zoom;
	else if (keycode == 49)
		begin(f);
	create_fractal(f);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *f)
{
	f->x2 = (x / f->zoom + f->x2) - (x / (f->zoom * 2.0));
	f->y2 = (y / f->zoom + f->y2) - (y / (f->zoom * 2.0));
	f->zoom *= 2.0;
	f->iter++;
}

void	ft_zoom_minus(int x, int y, t_fractol *f)
{
	f->x2 = (x / f->zoom + f->x2) - (x / (f->zoom / 2.0));
	f->y2 = (y / f->zoom + f->y2) - (y / (f->zoom / 2.0));
	f->zoom /= 2.0;
	f->iter--;
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, f);
	else if (mousecode == 5 || mousecode == 2)
		ft_zoom_minus(x, y, f);
	create_fractal(f);
	return (0);
}
