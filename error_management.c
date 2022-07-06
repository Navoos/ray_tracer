/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:15:49 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/06/27 20:15:49 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void	print_and_exit(const char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	*xalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		print_and_exit("ERROR : malloc failed");
	return (ptr);
}
