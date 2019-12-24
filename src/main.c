/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:23:05 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/24 08:30:46 by vlaroque         ###   ########.fr       */
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
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			ft_color_pix(img, x, y, 0x102 * julia(data->x_or + (x * data->pix_off),
						data->y_or + (y * data->pix_off), 10000));
			x++;
		}
		y++;
	}
	return (1);
}

int		mouse_pos_hook(int x, int y, t_data *data)
{
	printf("pos = %d %d\n", x, y);
	return (0);
}

int		mouse_wheel_hook(int button, int x, int y, t_data *data)
{
	t_coord x_pix;
	t_coord y_pix;

	x -= WIDTH / 2 - 400;
	y -= HEIGHT / 2 - 400;
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
	fill_img(data, data->imgdata);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgdata->img_ptr,
			WIDTH / 2 - 400, HEIGHT / 2 - 400);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 120, 120, 123456, "Hello");
	return (0);
}

int		main(int ac, char **av)
{
	t_data	data;

	if (!(data.mlx_ptr = mlx_init()))
		return (0);
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fdf")))
		return (0);
	if (!(data.imgdata = new_img(data.mlx_ptr, 800, 800)))
		return (0);
	data.x_or = -1.0;
	data.y_or = -1.0;
	data.pix_off = 1.0 / 400;
	fill_img(&data, data.imgdata);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.imgdata->img_ptr,
			WIDTH / 2 - 400, HEIGHT / 2 - 400);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 120, 120, 123456, "Hello");
//	mlx_hook(data.win_ptr, 6, 1L << 6, &mouse_pos_hook, (void *)&data);
	mlx_hook(data.win_ptr, 4, 1L << 2, &mouse_wheel_hook, (void *)&data);
	mlx_hook(data.win_ptr, 2, 0, &key_hook, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
