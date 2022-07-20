/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:42:32 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/07/13 15:42:32 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_mat44	mul_mat44_ref(t_mat44 a, t_mat44 b)
{
	int	i;
	int	j;
	t_mat44	ret;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ret.mat[i][j] = 
				a.mat[i][0] * b.mat[0][j] +
				a.mat[i][1] * b.mat[1][j] +
				a.mat[i][2] * b.mat[2][j] +
				a.mat[i][3] * b.mat[3][j];
		}
	}
	return (ret);
}

void	init(double	*mat[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				*mat[i][j] = 1;
			else
				*mat[i][j] = 0;
		}
	}
}
