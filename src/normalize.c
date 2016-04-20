#include "rt.h"

void	normalize(t_vec3 *a)
{
	a->x = a->x / distance(a);
	a->y = a->y / distance(a);
	a->z = a->z / distance(a);
}
