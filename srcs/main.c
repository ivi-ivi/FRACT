/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 01:11:04 by mcrissy           #+#    #+#             */
/*   Updated: 2020/08/10 15:00:15 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_fractal(t_fractol *f)
{
	if (f->iter < 0)
		f->iter = 0;
	pthread(f);
}

void	begin(t_fractol *f)
{
	if (f->fractal == MAN)
		init_man(f);
	else if (f->fractal == JUL)
		init_jul(f);
	else if (f->fractal == HEA)
		init_heart(f);
	else if (f->fractal == CM)
		init_cel_man(f);
	create_fractal(f);
}

void	mlx_window(t_fractol *f)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, HEIGHT, WIDTH, "Fractol");
	f->pic = mlx_new_image(f->mlx, HEIGHT, WIDTH);
	f->pic_ptr = mlx_get_data_addr(f->pic,
			&f->bpp, &f->sl, &f->en);
}

int		cmp_fractal(char *str, t_fractol *f)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		f->fractal = MAN;
	else if (ft_strcmp(str, "julia") == 0)
		f->fractal = JUL;
	else if (ft_strcmp(str, "heart") == 0)
		f->fractal = HEA;
	else if (ft_strcmp(str, "celtic_mandelbrot") == 0)
		f->fractal = CM;
	else
	{
		ft_putendl("Type name: mandelbrot"); 
		ft_putendl("julia");
		ft_putendl("celtic_mandelbrot");
		ft_putendl("heart");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_fractol	*f;

	if (argc != 2)
	{
		ft_putendl("Type name: mandelbrot");
		ft_putendl("julia");
		ft_putendl("celtic_mandelbrot");
		ft_putendl("heart");
	}
	else
	{
		if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
			return (1);
		if ((cmp_fractal(argv[1], f)) == 0)
			return (0);
		mlx_window(f);
		begin(f);
		mlx_hooks_loop(f);
	}
	return (0);
}
