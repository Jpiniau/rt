#include "rt.h"
#include <stdio.h>

float	intersect_cone(t_ray *ray, t_obj *cone)
{
	t_vec3	x;
	double	a;
	double	b;
	double	c;
	double	delta;

	/*	diff.x = ray->o.x - cone->center.x;
		diff.y = ray->o.y - cone->center.y;
		diff.z = ray->o.z - cone->center.z;
		a = ray->d.x * ray->d.x - ray->d.y * ray->d.y + ray->d.z * ray->d.z;
		b = ray->d.x * diff.x - ray->d.y * diff.y + ray->d.z * diff.z;
		c = diff.x * diff.x + diff.z * diff.z - diff.y * diff.y;
		delta = b * b - a * c;
		*/
	add_vec3(&(ray->o), &(cone->pos), &x);
	a = dot_product(&(ray->d), &(ray->d)) - (1 + cone->angle * cone->angle) * dot_product(&(ray->d), &(cone->n)) * dot_product(&(ray->d), &(cone->n));
	b = 2 * (dot_product(&(ray->d), &x) - (1 + cone->angle * cone->angle) * dot_product(&(ray->d), &(cone->n)) * dot_product(&x, &(cone->n)));
	c = dot_product(&x, &x) - (1 + cone->angle * cone->angle) * dot_product(&x, &(cone->n)) * dot_product(&x, &(cone->n));
	delta = b * b - 4 * a * c;
	return (intersect_point(a, b, delta));
}
