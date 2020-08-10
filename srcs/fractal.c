/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 01:04:16 by mcrissy           #+#    #+#             */
/*   Updated: 2020/08/07 01:04:16 by mcrissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*which_fract(t_fractol *f)
{
	if (f->fractal == MAN)
		mandelbrot(f);
	else if (f->fractal == JUL)
		julia(f);
	else if (f->fractal == CM)
		celtic_mandelbrot(f);
	else
		heart(f);
	return (0);
}

void	*fractal_start(void *mas)
{
	t_fractol	*f;
	int			tmp;

	f = (t_fractol *)mas;
	f->x = 0;
	tmp = f->y;
	while (f->x < WIDTH)
	{
		f->y = tmp;
		while (f->y < HEIGHT)
		{
			which_fract(f);
			f->y++;
		}
		f->x++;
	}
	return (mas);
}

void	pthread(t_fractol *f)
{
	t_fractol	mas[THREAD_NUM];
	pthread_t	t[THREAD_NUM];
	int			i;

	i = 0;
	while (i < THREAD_NUM)
	{
		ft_memcpy((void*)&mas[i], (void*)f, sizeof(t_fractol));
		mas[i].y = ((double)(1.00 / THREAD_NUM) * WIDTH) * i;
		mas[i].y_max = ((double)(1.00 / THREAD_NUM) * WIDTH) * (i + 1);
		pthread_create(&t[i], NULL, fractal_start, &mas[i]);
		++i;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx, f->window, f->pic, 0, 0);
}
