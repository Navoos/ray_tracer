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


int	hit_sphere(const t_vec3 center, const double radius, const t_ray *ray)
{
	t_vec3		oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = add_vec3_ref(ray->src , mul_scalar_ref(center, -1));
	a = dot(ray->dest,ray->dest);
	b = 2.0 * dot(oc, ray->dest);	
	c = dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant >= 0);
}

t_vec3	ray_color(const t_ray *ray)
{
	if (hit_sphere((t_vec3){0,0,-1}, 0.7, ray))
		return ((t_vec3) {1,0,1});
	double t = 0.5 * ((normalize_vec3_ref(ray->dest)).y + 1.0);
	return (add_vec3_ref(mul_scalar_ref((t_vec3){1., 1., 1.}, (double) 1.-t), mul_scalar_ref((t_vec3){.5, .7, 1.}, t)));
}

void draw_image(t_data *data)
{
	double focal_length = 1.0;
	t_vec3	lower_left_corner = add_vec3_ref((t_vec3) {0,0,0},
			(t_vec3)mul_scalar_ref((t_vec3) {VIEWPORT_WIDTH, 0, 0}, (double) -1/2));
	lower_left_corner = add_vec3_ref(lower_left_corner, mul_scalar_ref((t_vec3) {0, VIEWPORT_HEIGHT, 0}, (double)-1/2));
	lower_left_corner = add_vec3_ref(lower_left_corner, mul_scalar_ref((t_vec3) {0, 0, focal_length}, -1));
	for (int j = HEIGHT - 1; j >= 0; --j)
	{
		printf("\rLines remaining: %d", j);fflush(stdout);
		for (int i = 0;i < WIDTH; ++i)
		{
			double u = (double) i / WIDTH;
			double v = (double) j / HEIGHT;
			t_ray *ray = new_ray();
			ray->src = (t_vec3) {0, 0, 0}; 
			ray->dest = add_vec3_ref(lower_left_corner, mul_scalar_ref((t_vec3){VIEWPORT_WIDTH, 0, 0}, u)); 
			ray->dest = add_vec3_ref(ray->dest, mul_scalar_ref(mul_scalar_ref((t_vec3) {0, VIEWPORT_HEIGHT, 0}, v), -1));
			ray->dest = add_vec3_ref(ray->dest, mul_scalar_ref((t_vec3) {0,0,0}, -1));
			t_vec3	color = ray_color(ray);
			fill_pixel(data, i, j, create_trgb(0, color.x * 255, color.y * 255, color.z * 255));
			free(ray);
		}
	}
}

int	main(void)
{
	t_data			data;

	data.mlx = mlx_init();
	if (!data.mlx)
		print_and_exit("ERROR : could not load mlx");
	data.window = mlx_new_window(data.mlx, (int) WIDTH, (int)HEIGHT, "ray tracer");
	if (!data.window)
		print_and_exit("ERROR : could not create window");
	create_img(&data);
	draw_image(&data);
	mlx_put_image_to_window(data.mlx, data.window, data.img_data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
