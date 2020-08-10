/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 02:16:48 by mcrissy           #+#    #+#             */
/*   Updated: 2020/08/10 01:51:38 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_jul(t_fractol *f)
{
	f->zoom = 220;
	f->x2 = -1.8;
	f->y2 = -1.8;
	f->c_re = 0.36;
	f->c_i = 0.36;
	f->julia_mouse = 1;
}

void	julia(t_fractol *f)
{
	f->z_re = f->x / f->zoom + f->x2;
	f->z_i = f->y / f->zoom + f->y2;
	f->iter = 0;
	while (f->z_re * f->z_re + f->z_i
		* f->z_i < 4 && f->iter < MAX_ITER_JULIA)
	{
		f->tmp = f->z_re;
		f->z_re = f->z_re * f->z_re -
		f->z_i * f->z_i - 0.8 + (f->c_re / WIDTH);
		f->z_i = 2 * f->z_i * f->tmp + f->c_i / WIDTH;
		f->iter++;
	}
	if (f->iter == MAX_ITER_JULIA)
		put_pxl_to_pic(f, f->x, f->y, 0x000000);
	else
		put_pxl_to_pic(f, f->x, f->y, color(f->iter, f));
}
