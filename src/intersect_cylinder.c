#include "rt.h"

float	intersect_cylinder(t_ray *ray, t_obj *cylinder)
{
	t_vec3	x;
	float	a;
	float	b;
	float	c;
	float	delta;

	add_vec3(&(ray->o), &(cylinder->pos), &x);
	a = dot_product(&(ray->d), &(ray->d)) - (dot_product(&(ray->d), &(cylinder->n)) * dot_product(&(ray->d), &(cylinder->n)));
	b = 2 * (dot_product(&(ray->d), &x) - (dot_product(&(ray->d), &(cylinder->n)) * dot_product(&x, &(cylinder->n))));
	c = dot_product(&x, &x) - (dot_product(&x, &(cylinder->n)) * dot_product(&x, &(cylinder->n))) - (cylinder->size * cylinder->size);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else
		return (intersect_point(a, b, delta));
}
