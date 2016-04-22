#include "rt.h"

void 	init_shadow_ray(t_ray *ray, t_vec3 light, t_vec3 point)
{
	init_vec3(&(ray->o), point.x, point.y, point.z);
	init_vec3(&(ray->d), light.x - point.x, light.y - point.y, light.z - point.z);
	normalize(&(ray->d));
}
