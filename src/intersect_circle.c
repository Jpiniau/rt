/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:58:29 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/31 18:43:36 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	square(float a)
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
	a = square(env->cam_dir.x) + square(env->cam_dir.y) + square(env->cam_dir.z);
	b = 2 * (env->cam_dir.x * (x - circle->pos.x) + env->cam_dir.y * 
			(y - circle->pos.y) + env->cam_dir.z * (z - circle->pos.z));
	c = square(x - circle->pos.x) + square(y - circle->pos.y) +
			square(z - circle->pos.z) - square (circle->size);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else 
		return (1);
}
