/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:14:09 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/15 12:40:49 by fsidler          ###   ########.fr       */
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

# define MINX mlx->minx
# define MAXX mlx->maxx
# define MINY mlx->miny
# define MAXY mlx->maxy

# define MOTION_NOTIFY		6
# define PTR_MOTION_MASK	(1L << 6)

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
	double		minx;
	double		maxx;
	double		miny;
	double		maxy;
	double		iter;
	double		freq;
	int			color;
}				t_mlx;

int				ft_draw(t_mlx *mlx);
int				ft_instructions(void);
int				ft_color(int i, t_mlx *mlx);
int				key_hook(int keycode, t_mlx *mlx);
int				ft_motion(int x, int y, t_mlx *mlx);
void			put_pixel(t_f *f, int x, int y, int color);

#endif
