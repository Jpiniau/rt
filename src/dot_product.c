#include "rt.h"

float	dot_product(t_vec3 *a, t_vec3 *b)
{
	float	result;

	result = a->x * b->x + a->y * b->y + a->z * b->z;
	return (result);
}
