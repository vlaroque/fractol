/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:26:21 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/24 08:15:21 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1920
# define HEIGHT 1080
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


t_img		*new_img(void *mlx_ptr, int width, int height);
int			ft_color_pix(t_img *img, int x, int y, int color);

int		julia(t_coord x, t_coord y, int max);
#endif

