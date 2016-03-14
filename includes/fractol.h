/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:14:09 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/14 13:10:55 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <../libft/libft.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WIN_W 800
# define WIN_H 800

typedef struct	s_f
{
	void		*img;
	double		pr;
	double		pi;
	double		cr;
	double		ci;
	int			bpp;
	int			endian;
	int			size_line;
	char		*d;
	int			nb;
}				t_f;

typedef struct	s_mlx
{
	t_f			*f;
	void		*mlx;
	void		*win;
	double		iter;
	double		freq;
	int			color;
}				t_mlx;

int				ft_draw(t_mlx *mlx);
int				ft_color(int i, t_mlx *mlx);
void			put_pixel(t_f *f, int x, int y, int color);

#endif
