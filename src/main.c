/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:23:05 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/16 09:55:11 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fractol.h"

int		key_hook(int keycode, t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->imgdata->img_ptr, 0, 0);
	return (0);
}

int		fill_img(t_data *data, t_img *img)
{
	int		x;
	int		y;

	y = 0;
	while (y < IMG_H)
	{
		x = 0;
		while (x < IMG_W)
		{
			ft_color_pix(img, x, y, 0x102 * mandelbrot(data->x_or + (x * data->pix_off),
						data->y_or + (y * data->pix_off), 100));
			x++;
		}
		y++;
	}
	return (1);
}

int		mouse_wheel_hook(int button, int x, int y, t_data *data)
{
	t_coord x_pix;
	t_coord y_pix;

	x -= WIN_W / 2 - IMG_W / 2;
	y -= WIN_H / 2 - IMG_H / 2;
	if (button == 5)
	{
		x_pix = data->x_or + (x * data->pix_off);
		y_pix = data->y_or + (y * data->pix_off);
		data->pix_off *= 0.9;
		data->x_or = x_pix - (x * data->pix_off);
		data->y_or = y_pix - (y * data->pix_off);
	}
	else if (button == 4)
	{
		x_pix = data->x_or + (x * data->pix_off);
		y_pix = data->y_or + (y * data->pix_off);
		data->pix_off *= 10.0 / 9.1;
		data->x_or = x_pix - (x * data->pix_off);
		data->y_or = y_pix - (y * data->pix_off);
	}
	//fill_img(data, data->imgdata);
	show_matrix(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 120, 120, 123456, "Hello");
	return (0);
}

int		main(int ac, char **av)
{
	t_data	data;

	if (!(data.mlx_ptr = mlx_init()))
		return (0);
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, "Fdf")))
		return (0);
	if (!(data.imgdata = new_img(data.mlx_ptr, IMG_W, IMG_H)))
		return (0);
	data.x_or = -1.0;
	data.y_or = -1.0;
	data.pix_off = 1.0 / 400;
	data.fract = &julia;
	//fill_img(&data, data.imgdata);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.imgdata->img_ptr,
	////		WIN_W / 2 - IMG_W / 2, WIN_H / 2 - IMG_H / 2);
	show_matrix(&data);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 120, 120, 123456, "Hello");
//	mlx_hook(data.win_ptr, 6, 1L << 6, &mouse_pos_hook, (void *)&data);
	mlx_hook(data.win_ptr, 4, 1L << 2, &mouse_wheel_hook, (void *)&data);
	mlx_hook(data.win_ptr, 2, 0, &key_hook, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
