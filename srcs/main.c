/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:39:33 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/14 16:56:21 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_color(int i, t_mlx *mlx)
{
	int		red;
	int		green;
	int		blue;
	double	co;

	if (i == mlx->iter)
		return (0);
	co = mlx->freq * (i + 1);
	red = cos(co) * 127 + 128;
	green = cos(co + mlx->color) * 127 + 128;
	blue = cos(co + 2 * mlx->color) * 127 + 128;
	return ((red << 16) + (blue << 8) + green);
}

void			put_pixel(t_f *f, int x, int y, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (f->bpp / 8) + y * (f->size_line);
	while (i < (f->bpp / 8))
	{
		f->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

static t_f		*init_fract(char *s)
{
	t_f	*f;

	if (!(f = (t_f *)malloc(sizeof(t_f))))
		return (NULL);
	f->cr = -1.1380;
	f->ci = 0.2403;
	f->pr = 0.0;
	f->pi = 0.0;
	f->nb = ft_atoi(s);
	return (f);
}

static t_mlx	*init_mlx(char *s)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->f = init_fract(s)))
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->f->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "fractol");
	mlx->f->d = mlx_get_data_addr(mlx->f->img, &mlx->f->bpp, &mlx->f->size_line\
				, &mlx->f->endian);
	mlx->minx = -2.2;
	mlx->miny = -2.2;
	mlx->maxx = 4.4;
	mlx->maxy = 4.4;
	mlx->freq = 0.1;
	mlx->iter = 16.0;
	mlx->color = 2;
	return (mlx);
}

int				main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2 || ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 3)
	{
		ft_putendl("usage: ./fractol 1/2/3 (Julia/Mandelbrot/Tricorn)");
		return (0);
	}
	if ((mlx = init_mlx(argv[1])) != NULL)
	{
		ft_instructions();
		ft_draw(mlx);
		mlx_key_hook(mlx->win, key_hook, mlx);
		mlx_loop(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	return (0);
}
