#include "rt.h"

void	sus_vec3(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;
}
