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

static float	reflect(t_vec3 point, t_ray *ray, t_vec3 n, t_light light)
{
	t_vec3	v;
	t_vec3	r;
	t_vec3	l;
	float	refl;

	sus_vec3(&light.pos, &point, &l);
	//	l.x = light.center.x - point.x;
	//	l.y = light.center.y - point.y;
	//	l.z = light.center.z - point.z;
	normalize(&l);
	sus_vec3(&ray->o, &point, &v);
	//	v.x = ray->o.x - point.x;
	//	v.y = ray->o.y - point.y;
	//	v.z = ray->o.z - point.z;
	normalize(&v);
	if (dot_product(&n, &l) <= 0)
		return (0);
	r = vecsvec(l, vecmf(n, 2 * dot_product(&n, &l)));
	normalize(&r);
	refl = dot_product(&ray->d, &r);
	refl = refl < 0 ? 0 : refl;
	refl = refl > 1 ? 1 : refl;
	return (pow(refl, 4048));
}

float		intersect_light(t_vec3 point, t_ray *ray, t_obj *obj, t_light light)
{
	float		dif;
	float		refl;
	int			rgb[3];
	t_vec3		dis;
	t_vec3		normal;

	rgb[0] = obj->color.x;
	rgb[1] = obj->color.y;
	rgb[2] = obj->color.z;
	sus_vec3(&light.pos, &point, &dis);
	//	dis.x = light.center.x - point.x;
	//	dis.y = light.center.y - point.y;
	//	dis.z = light.center.z - point.z;
	normalize(&dis);
	if (get_normal(&normal, obj, &point, ray))
		return (rgb_int(obj->color.x, obj->color.y, obj->color.z));
	dif = dot_product(&dis, &normal);
	refl = reflect(point, ray, normal, light);
	dif = dif < 0 ? 0 : dif;
	dif = dif > 1 ? 1 : dif;
	rgb[0] = rgb[0] * (dif + AMB) + refl * 255;
	rgb[1] = rgb[1] * (dif + AMB) + refl * 255;
	rgb[2] = rgb[2] * (dif + AMB) + refl * 255;
	rgb[0] = rgb[0] > 255 ? 255 : rgb[0];
	rgb[1] = rgb[1] > 255 ? 255 : rgb[1];
	rgb[2] = rgb[2] > 255 ? 255 : rgb[2];
	return (rgb_int(rgb[0], rgb[1], rgb[2]));
}
