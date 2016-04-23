#include "rt.h"

static t_obj	*objnew(t_obj *obj)
{
	t_obj	*ret;

	ret = (t_obj *)malloc(sizeof(t_obj));
	ret->size = obj->size;
	ret->power = obj->power;
	ret->ref = obj->ref;
	ret->pos = obj->pos;
	ret->n = obj->n;
	normalize(&ret->n);
	ret->color = obj->color;
	ret->angle = obj->angle;
	return (ret);
}

void	lightpushback(t_env *e, t_obj *obj)
{
	t_obj	*obje;

	obje = e->light;
	if (obje)
	{
		while (obje->next)
			obje = obje->next;
		obje->next = objnew(obj);
	}
	else
		e->obj = objnew(obj);
}
