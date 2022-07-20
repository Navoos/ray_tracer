/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:15:27 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/06/27 20:15:27 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER
# define RAY_TRACER
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include "minilibx/mlx.h"

# define WIDTH 1080
# define ASPECT_RATIO 1.77777778
# define HEIGHT (WIDTH/ASPECT_RATIO)
# define VIEWPORT_HEIGHT 2.0
# define VIEWPORT_WIDTH 3.55555556
# define PI 3.14159265359
# define RADIANS(d) (double)d * ((double)PI / 180.0)


typedef struct t_vec3
{
  double x;
  double y;
  double z;
}t_vec3;


typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	t_img_data	img_data;
}	t_data;

typedef struct s_ray
{
	t_vec3	src;
	t_vec3	dest;
}	t_ray;
typedef struct s_mat44
{
	double mat[4][4];
	void	(*init)(double *mat[4][4]);
}	t_mat44;
/********** ERROR_MANAGEMENT **********/
void	print_and_exit(const char *msg);
void	*xalloc(size_t size);
/********** 			DRAW			 **********/
void	create_img(t_data	*data);
void	fill_pixel(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
/********** 			VEC3 			 **********/
void update_vec3(t_vec3	*v, double x, double y, double z);
void vec3_mv(t_vec3 origin, t_vec3 *dst);
double	get_length(t_vec3 v);
t_vec3	*normalize_vec3(const t_vec3 v);
t_vec3	*mul_vec3(t_vec3 a, t_vec3 b);
t_vec3	*mul_scalar(t_vec3 a, double scalar);
t_vec3	*add_vec3(t_vec3 a, t_vec3 b);
t_vec3	*new_vec3(double x, double y, double z);
t_vec3	mul_vec3_ref(t_vec3 a, t_vec3 b);
t_vec3	mul_scalar_ref(t_vec3 a, double scalar);
t_vec3	add_vec3_ref(t_vec3 a, t_vec3 b);
t_vec3	add_scalar_ref(t_vec3 v, double scalar);
t_vec3	normalize_vec3_ref(t_vec3 v);
t_vec3	cross_vec3_ref(t_vec3 a, t_vec3 b);
double	dot(const t_vec3 v1, const t_vec3 v2);
/********** 			RAY 			 **********/
t_ray	*new_ray(void);

#endif
