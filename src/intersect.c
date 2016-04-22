/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:55:03 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/22 18:22:06 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj		*intersect(t_ray *ray, t_obj *obj, t_vec3 *point)
{
	float	t;
	float	t_tmp;
	t_obj	*tobj;

	tobj = NULL;
	t = -1;
	while (obj != NULL)
	{
		if (!ft_strcmp(obj->ref, "sphere"))
		{
			t_tmp = intersect_circle(ray, obj);
		}
		else if (!ft_strcmp(obj->ref, "plane"))
		{
			t_tmp = intersect_plane(ray, obj);
		}
		else if (!ft_strcmp(obj->ref, "cylinder"))
		{
			t_tmp = intersect_cylinder(ray, obj);
		}
		else if (!ft_strcmp(obj->ref, "cone"))
		{
			t_tmp = intersect_cone(ray, obj);
		}
		if (tobj == NULL && t_tmp >= 0)
		{
			t = t_tmp;
			tobj = obj;
		}
		else if (t_tmp >= 0)
		{
			if (t > t_tmp)
			{
				t = t_tmp;
				tobj = obj;
			}
		}
		obj = obj->next;
	}
	if (tobj != NULL)
	{
		point->x = ray->o.x + t * ray->d.x * 0.9995;
		point->y = ray->o.y + t * ray->d.y * 0.9995;
		point->z = ray->o.z + t * ray->d.z * 0.9995;
	}
	return (tobj);
}
