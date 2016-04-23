/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:40:14 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/23 19:07:14 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	rgb_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int ambient_color(int color)
{
	int	rgb[3];

	rgb[2] = color & 255;
	rgb[1] = (color>>8) & 255;
	rgb[0] = (color>>16) & 255;

	rgb[0] *= 0.2;
	rgb[1] *= 0.2;
	rgb[2] *= 0.2;
	return (rgb_hex(rgb[0], rgb[1], rgb[2]));
}

int scene(t_env *env)
{
	int		x;
	int		y;
	t_obj	*obj;
	t_ray	ray;
//	t_ray	ray2;
	//t_light	light;
	t_vec3	point;

	//init_vec3(&(light.pos), -8, 10, -20);
	x = -1;
	obj = NULL;
	while (++x < env->width)
	{
		y = -1;
		while (++y < env->height)
		{
			init_ray(&ray, x, y, env);
			obj = intersect(&ray, env->obj, &point);
			if (obj != NULL)
			{
			//	init_shadow_ray(&ray2, light.pos, point);
			//	if (intersect_shadow(&ray2, obj, &light) != NULL)
			//		ft_pixel_put(env, x, y, ambient_color(rgb_hex(obj->color.x, obj->color.y, obj->color.z)));
			//	else
					//ft_pixel_put(env, x, y, intersect_light(point, &ray, obj, light));
					ft_pixel_put(env, x, y, light(point, &ray, obj, env->light));
					//ft_pixel_put(env, x, y, rgb_hex(obj->color.x, obj->color.y, obj->color.z));
			}
			else
				ft_pixel_put(env, x, y, 0x000000);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
