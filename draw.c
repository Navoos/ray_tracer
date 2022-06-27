/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:37:47 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/06/27 20:37:47 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void	create_img(t_data	*data)
{
	data->img_data.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_data.addr = mlx_get_data_addr(data->img_data.img, &data->img_data.bits_per_pixel, &data->img_data.line_length,
			&data->img_data.endian);
}

void	fill_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_data.addr + (y * data->img_data.line_length + x * (data->img_data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
