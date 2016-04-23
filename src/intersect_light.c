#include "rt.h"
#include <math.h>

#include <stdio.h>

static int	rgb_int(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static t_vec3	vecsvec(t_vec3 a, t_vec3 b)
{
	t_vec3 result;

	init_vec3(&result, a.x - b.x, a.y - b.y, a.z - b.z);
	return (result);
}

static t_vec3	vecmf(t_vec3 a, float b)
{
	t_vec3	result;

	init_vec3(&result, a.x * b, a.y * b, a.z * b);
	return (result);
}

static float	reflect(t_vec3 point, t_ray *ray, t_vec3 n, t_obj *light)
{
	t_vec3	r;
	t_vec3	l;
	float	refl;

	sus_vec3(&light->pos, &point, &l);
	normalize(&l);
	r = vecsvec(l, vecmf(n, 2 * dot_product(&n, &l)));
	normalize(&r);
	refl = dot_product(&ray->d, &r);
	refl = refl < 0 ? 0 : refl;
	refl = refl > 1 ? 1 : refl;
	return (pow(refl, 500));
}

static float	intersect_light(t_vec3 point, t_ray *ray, t_obj *obj, t_obj *light)
{
	float		dif;
	float		refl;
	float		rgb[3];
	t_vec3		dis;
	t_vec3		normal;

	sus_vec3(&light->pos, &point, &dis);
	normalize(&dis);
	if (get_normal(&normal, obj, &point, ray))
		return (rgb_int(obj->color.x, obj->color.y, obj->color.z));
	dif = dot_product(&dis, &normal);
	refl = reflect(point, ray, normal, light);
	dif = dif < 0 ? 0 : dif;
	dif = dif > 1 ? 1 : dif;
	rgb[0] = obj->color.x;
	rgb[1] = obj->color.y;
	rgb[2] = obj->color.z;
	rgb[0] = rgb[0] * (dif + AMB) + refl * 200;
	rgb[1] = rgb[1] * (dif + AMB) + refl * 200;
	rgb[2] = rgb[2] * (dif + AMB) + refl * 200;
	rgb[0] = rgb[0] > 255 ? 255 : rgb[0];
	rgb[1] = rgb[1] > 255 ? 255 : rgb[1];
	rgb[2] = rgb[2] > 255 ? 255 : rgb[2];
	return (rgb_int(rgb[0], rgb[1], rgb[2]));
}

float			light(t_vec3 point, t_ray *ray, t_obj *obj, t_obj *light)
{
	int		tmp;
	int		rgb[3];

	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	while (light != NULL)
	{
		tmp = intersect_light(point, ray, obj, light);
		rgb[2] += tmp & 255;
		rgb[1] += tmp>>8 & 255;
		rgb[0] += tmp>>16 & 255;
		light = light->next;
	}
	rgb[0] = rgb[0] > 255 ? 255 : rgb[0];
	rgb[1] = rgb[1] > 255 ? 255 : rgb[1];
	rgb[2] = rgb[2] > 255 ? 255 : rgb[2];
	return (rgb_int(rgb[0], rgb[1], rgb[2]));
}
