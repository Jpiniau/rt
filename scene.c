/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 20:11:22 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/27 20:16:00 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	scene(t_env *env)
{
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			init_ray(&ray, x, y);
			obj = intersect_object(&ray, scene);
			if (obj != NULL)
			{
				ft_pixel_put(env, x, y, obj->color);
			}
			else
				ft_pixel_put(env, x, y, 0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
}
