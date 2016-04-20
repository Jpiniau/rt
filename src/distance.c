#include "rt.h"
#include <math.h>

float	distance(t_vec3 *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}
