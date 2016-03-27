/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:02:34 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/05 16:44:30 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_pixel_put(t_env *env, int color)
{
	unsigned int	bytes;
	unsigned int	d;
	size_t			j;

	bytes = env->data_img.bpp / 8;
	d = env->f.x * bytes + env->f.y * env->data_img.sizeline;
	j = -1;
	while (++j < bytes)
	{
		env->data[d + j] = color;
		color >>= 8;
	}
	return (0);
}
