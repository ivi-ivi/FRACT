/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 02:16:15 by mcrissy           #+#    #+#             */
/*   Updated: 2020/08/07 15:29:15 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_man(t_fractol *f)
{
	f->zoom = 240;
	f->x2 = -2.05;
	f->y2 = -1.3;
}

void	mandelbrot(t_fractol *f)
{
	f->c_re = f->x / f->zoom + f->x2;
	f->c_i = f->y / f->zoom + f->y2;
	f->z_re = 0;
	f->z_i = 0;
	f->iter = 0;
	while (f->z_re * f->z_re + f->z_i *
			f->z_i < 4 && f->iter < MAX_ITER)
	{
		f->tmp = f->z_re;
		f->z_re = f->z_re * f->z_re -
			f->z_i * f->z_i + f->c_re;
		f->z_i = 2 * f->z_i * f->tmp + f->c_i;
		f->iter++;
	}
	if (f->iter == MAX_ITER)
		put_pxl_to_pic(f, f->x, f->y, 0x000000);
	else
		put_pxl_to_pic(f, f->x, f->y, color(f->iter, f));
}
