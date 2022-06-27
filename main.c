/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:05:49 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/06/27 20:05:49 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

int	main(void)
{
	t_data			data;

	data.mlx = mlx_init();
	if (!data.mlx)
		print_and_exit("ERROR : could not load mlx");
	data.window = mlx_new_window(data.mlx, WIDTH, HEIGHT, "ray tracer");
	if (!data.window)
		print_and_exit("ERROR : could not create window");
	create_img(&data);
	fill_pixel(&data, 100, 100, 0x00ff0000);
	mlx_put_image_to_window(data.mlx, data.window, data.img_data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
