#include "rt.h"
#include <stdlib.h>

t_obj	*intersect_shadow(t_ray *ray, t_obj *obj, t_light *light)
{
	float	t;
	float	t_tmp;
	t_obj	*tobj;

	tobj = NULL;
	if (ray->d.x > 0)
		t = (light->pos.x - ray->o.x) / ray->d.x;
	else if (ray->d.y > 0)
		t = (light->pos.y - ray->o.y) / ray->d.y;
	else if (ray->d.z > 0)
		t = (light->pos.z - ray->o.z) / ray->d.z;
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
		if (tobj == NULL && t_tmp > 0 && t_tmp < t)
		{
			t = t_tmp;
			tobj = obj;
		}
		else if (t_tmp > 0 && t_tmp < t)
		{
				t = t_tmp;
				tobj = obj;
		}
		obj = obj->next;
	}
	return (tobj);
}
