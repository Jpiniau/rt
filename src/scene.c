/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:40:14 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/31 18:40:34 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	rgb_hex(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int scene(t_env *env)
{
	int		x;
	int		y;
	t_obj	*obj;

	x = -1;
	obj = NULL;
	while (++x < env->width)
	{
		y = -1;
		while (++y < env->height)
		{
			obj = intersect(env, env->obj, x, y);
			if (obj != NULL)
			{
				ft_pixel_put(env, x, y, rgb_hex(obj->color.x, obj->color.y, obj->color.z));
			}
			else
				ft_pixel_put(env, x, y, 0xFF0000);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
