#include "rt.h"

float	intersect_plane(t_ray *ray, t_obj *plane)
{
	float	t;
	t_vec3	diff;
	t_vec3	d;

	d.x = ray->d.x;
	d.y = ray->d.y;
	d.z = ray->d.z;
	diff.x = plane->pos.x - ray->o.x;
	diff.y = plane->pos.y - ray->o.y;
	diff.z = plane->pos.z - ray->o.z;
	t = dot_product(&plane->n, &diff) / dot_product(&plane->n, &d);
	return (t);
}
