/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:58:29 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/02 15:50:58 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	sqr(float a)
{
	return (a * a);
}

float	intersect_circle(t_env *env, t_obj *circle, int x, int y)
{
	float	a;
	float	b;
	float	c;
	float	delta;
	int		z;

	z = 0;
	a = sqr(env->cam_dir.x) + sqr(env->cam_dir.y) + sqr(env->cam_dir.z);
	b = 2 * (env->cam_dir.x * (x - circle->pos.x) + env->cam_dir.y * 
			(y - circle->pos.y) + env->cam_dir.z * (z - circle->pos.z));
	//c = sqr(x - circle->pos.x) + sqr(y - circle->pos.y) +
	//		sqr(z - circle->pos.z) - sqr (circle->size);
	c = sqr(circle->pos.x) + sqr(circle->pos.y) +
			sqr(circle->pos.z) + sqr(x) + sqr(y) + sqr(z) - 
			2 * (circle->pos.x * x + circle->pos.y * y + circle->pos.z * z) - 
			sqr (circle->size);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else if (delta == 0)
		return (0);
	else
		return (1);
}
