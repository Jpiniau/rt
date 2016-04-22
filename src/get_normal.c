#include "rt.h"

static void		get_cylinder_normal(t_vec3 *normal, t_obj *cylinder, t_vec3 *point, t_ray *ray, float t)
{
	t_vec3	v;
	float	m;

	sus_vec3(&(ray->o), &(cylinder->pos), &v);
	m = dot_product(&(ray->d), &(cylinder->n)) * t + dot_product(&v, &(cylinder->n));
	normal->x = point->x + cylinder->pos.x - cylinder->n.x * m;
	normal->y = point->y + cylinder->pos.y - cylinder->n.y * m;
	normal->z = point->z + cylinder->pos.z - cylinder->n.z * m;
	normalize(normal);
}

static void		get_cone_normal(t_vec3 *normal, t_obj *cone, t_vec3 *point, t_ray *ray, float t)
{
	t_vec3	v;
	float	m;

	sus_vec3(point, &cone->pos, &v);
	m = dot_product(&ray->d, &cone->n) * t + dot_product(&v, &cone->n);
	normal->x = point->x + cone->pos.x - (1 + cone->angle * cone->angle) * cone->n.x * m;
	normal->y = point->y + cone->pos.y - (1 + cone->angle * cone->angle) * cone->n.y * m;
	normal->z = point->z + cone->pos.z - (1 + cone->angle * cone->angle) * cone->n.z * m;
	normalize(normal);
}

static void		get_t(t_vec3 *point, t_ray *ray, float *t)
{
	if (ray->d.x > 0)
		*t = (point->x - ray->o.x) / ray->d.x;
	else if (ray->d.y > 0)
		*t = (point->y - ray->o.y) / ray->d.y;
	else if (ray->d.z > 0)
		*t = (point->z - ray->o.z) / ray->d.z;
}

int				get_normal(t_vec3 *normal, t_obj *obj, t_vec3 *point, t_ray *ray)
{
	float		t;

	get_t(point, ray, &t);
	if (!ft_strcmp(obj->ref, "cone"))
	{
		get_cone_normal(normal, obj, point, ray, t);
	}
	else if (!ft_strcmp(obj->ref, "cylinder"))
	{
		get_cylinder_normal(normal, obj, point, ray, t);
	}
	else if (!ft_strcmp(obj->ref, "plane"))
	{
		normal->x =  obj->n.x;
		normal->y =  obj->n.y;
		normal->z =  obj->n.z;
		normalize(normal);
	}
	else if (!ft_strcmp(obj->ref, "sphere"))
	{
		normal->x =  point->x - obj->pos.x;
		normal->y =  point->y - obj->pos.y;
		normal->z =  point->z - obj->pos.z;
		normalize(normal);
	}
	else
		return (1);
	return (0);
}
