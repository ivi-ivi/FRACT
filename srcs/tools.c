/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:06:07 by tglandai          #+#    #+#             */
/*   Updated: 2020/08/10 15:01:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	put_pxl_to_pic(t_fractol *f, int x, int y, int color)
{
	if (f->x2 < HEIGHT && f->y < WIDTH)
	{
		color = mlx_get_color_value(f->mlx, color);
		ft_memcpy(f->pic_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	mlx_hooks_loop(t_fractol *f)
{
	mlx_hook(f->window, 6, 1L < 6, julia_mouse_move, f);
	mlx_hook(f->window, 17, 0L, ft_close, f);
	mlx_key_hook(f->window, key_hook, f);
	mlx_mouse_hook(f->window, mouse_hook, f);
	mlx_loop(f->mlx);
}

int		color_2(int iter, t_fractol *f)
{
	if (iter > 30)
		f->color = COL_1;
	if (iter > 40)
		f->color = COL_2;
	if (iter > 50)
		f->color = COL_3;
	if (iter > 55)
		f->color = COL_4;
	return (f->color);
}

int		color(int iter, t_fractol *f)
{
	f->color = 0x000000;
	if (iter > 1.5)
		f->color = COL_6;
	if (iter > 2.5)
		f->color = COL_5;
	if (iter > 3)
		f->color = COL_4;
	if (iter > 4)
		f->color = COL_2;
	if (iter > 6)
		f->color = COL_3;
	if (iter > 8)
		f->color = COL_4;
	if (iter > 10)
		f->color = COL_5;
	if (iter > 20)
		f->color = COL_6;
	if (iter > 30)
		f->color = color_2(iter, f);
	return (f->color);
}
