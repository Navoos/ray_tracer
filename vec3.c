/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:48:03 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/07/06 21:48:03 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

inline void update_vec3(t_vec3	*v, double x, double y, double z)
{
	if (!v)
		return ;
	v->x = x;
	v->y = y;
	v->z = z;
}

inline void vec3_mv(t_vec3 origin, t_vec3 *dst)
{
	dst->x = origin.x;
	dst->y = origin.y;
	dst->z = origin.z;
}

t_vec3	*new_vec3(double x, double y, double z)
{
	t_vec3	*res;

	res = xalloc(sizeof(t_vec3));
	update_vec3(res, x, y, z);
	return (res);
}

inline double	get_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z)); 
}

t_vec3	*normalize_vec3(const t_vec3 v)
{
	double	length;
	t_vec3	*ret;

	length = get_length(v);
	ret = xalloc(sizeof(t_vec3));
	update_vec3(ret, v.x/length, v.y / length, v.z / length);
	return (ret);
}

t_vec3	normalize_vec3_ref(t_vec3 v)
{
	double	length;

	length = get_length(v);
	if (length <= 0)
		return (v);
	v.x = v.x / length;
	v.y = v.y / length;
	v.z = v.z / length;
	return (v);
}

t_vec3	mul_vec3_ref(t_vec3 a, t_vec3 b)
{
	a.x = a.x * b.x;
	a.y = a.y * b.y;
	a.z = a.z * b.z;
	return (a);
}

t_vec3	*mul_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	*res;

	res = xalloc(sizeof(t_vec3));
	update_vec3(res, a.x * b.x, a.y * b.y, a.z * b.z);
	return (res);
}

t_vec3	*mul_scalar(t_vec3 a, double scalar)
{
	t_vec3	*res;

	res = xalloc(sizeof(t_vec3));
	update_vec3(res, a.x * scalar, a.y * scalar, a.z * scalar);
	return (res);
}

t_vec3	add_scalar_ref(t_vec3 v, double scalar)
{
	v.x += scalar;
	v.y += scalar;
	v.z += scalar;
	return (v);
}

t_vec3	mul_scalar_ref(t_vec3 a, double scalar)
{
	a.x = a.x * scalar;
	a.y = a.y * scalar;
	a.z = a.z * scalar;
	return (a);
}

inline double dot(const t_vec3 v1, const t_vec3 v2)
{
	return ((double) v1.x * v2.x
			+			v1.y * v2.y
			+			v1.z * v2.z);
}

inline t_vec3	cross_vec3_ref(t_vec3 a, t_vec3 b)
{
	return ((t_vec3) {a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x});
}

t_vec3	*add_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	*res;

	res = xalloc(sizeof(t_vec3));
	update_vec3(res, a.x + b.x, a.y + b.y, a.z + b.z);
	return (res);
}

t_vec3	add_vec3_ref(t_vec3 a, t_vec3 b)
{
	a.x = a.x + b.x;
	a.y = a.y + b.y;
	a.z = a.z + b.z;
	return (a);
}
