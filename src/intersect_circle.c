#include "rt.h"
#include "libft.h"

float	intersect_circle(t_ray *ray, t_obj *circle)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	a = ray->d.x * ray->d.x + ray->d.y * ray->d.y + ray->d.z * ray->d.z;
	b = 2 * (ray->d.x * (ray->o.x - circle->pos.x) + ray->d.y * (ray->o.y - circle->pos.y) +
			ray->d.z * (ray->o.z - circle->pos.z));
	c = ((ray->o.x - circle->pos.x) * (ray->o.x - circle->pos.x) + (ray->o.y - circle->pos.y) * (ray->o.y - circle->pos.y) +
			(ray->o.z - circle->pos.z) * (ray->o.z - circle->pos.z)) - circle->size * circle->size;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else
		return (intersect_point(a, b, delta));
}
