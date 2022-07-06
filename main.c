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



t_vec	get_color(t_vec *ray_dst)
{
	t_vec		*unit_direction;
	t_vec		*res;
	double	t;

	unit_direction = normalize_vec3(ray_dst);
	t = unit_direction.y;
	free(unit_direction);
	res = calc_first_part(

}

void background(t_data	*data)
{

}

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
	mlx_put_image_to_window(data.mlx, data.window, data.img_data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
