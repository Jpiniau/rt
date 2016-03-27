/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:58:29 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/27 20:16:04 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static float	square(float a)
{
	return (a * a);
}

float	intersect_circle(t_cam *env, t_obj *circle, t_ray *ray)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	a = square(cam_dir->x) + square(cam_dir->y) + square(cam_dir->z);
	b = 2 * (cam_dir->x * (ray->x - circle->pos.x) + cam_dir->y * 
			(ray->y - circle->pos.y) + cam_dir->z * (ray->z - circle->pos.z));
	c = square(ray->x - circle->pos.x) + square(ray->y - circle->pos.y) +
			square(ray->z - circle->pos.z) - square (circle->size);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else 
		return (1);

}
