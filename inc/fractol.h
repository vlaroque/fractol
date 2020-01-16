/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:26:21 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/16 09:56:45 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_W 1920
# define WIN_H 1080
# define IMG_W 800
# define IMG_H 800
# include <stdio.h>

typedef double	t_coord;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixs;
	int		bits_in_pix;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			matrice[IMG_W * IMG_H];
	int			(*fract)(t_coord, t_coord, int);
	t_coord		pix_off;
	t_coord		x_or;
	t_coord		y_or;
	t_img		*imgdata;
}				t_data;

typedef struct	s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;


t_img		*new_img(void *mlx_ptr, int width, int height);
int			ft_color_pix(t_img *img, int x, int y, int color);

int		julia(t_coord x, t_coord y, int max);
int		mandelbrot(t_coord x, t_coord y, int max);

int		mouse_pos_hook(int x, int y, t_data *data);

int		matrix_erase(t_data *data);
int		matrix_to_img(t_data *data);
int		fill_matrix(t_data *data);
int		show_matrix(t_data *data);


int		flood_fill(t_data *data, int x, int y);
t_point point(int x, int y);
int		blackhole(t_data *data, t_point init, t_point pt, int dir);
#endif

