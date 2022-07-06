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
#include "minilibx/mlx.h"

# define WIDTH 720
# define HEIGHT 480


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
/********** ERROR_MANAGEMENT **********/
void	print_and_exit(const char *msg);
/********** 			DRAW			 **********/
void	create_img(t_data	*data);
void	fill_pixel(t_data *data, int x, int y, int color);
#endif
