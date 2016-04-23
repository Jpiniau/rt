/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:41:02 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/23 18:39:38 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

#include <stdio.h>

void	ft_put(t_obj *ret)
{
	printf("\n ref: %s \n size: %f \n power: %f \n pos: x: %f y: %f z: %f \n n: x: %f y: %f z: %f \n color : %f %f %f \n angle : %f\n",ret->ref ,ret->size, ret->power, ret->pos.x, ret->pos.y, ret->pos.z, ret->n.x, ret->n.y, ret->n.z, ret->color.x, ret->color.y, ret->color.z, ret->angle);
}

t_obj	*objnew(t_obj *obj)
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


void	ft_invvec3(t_obj *obj)
{
	obj->pos.x *= -1;
	obj->pos.y *= -1;
	obj->pos.z *= -1;
}

void	objpushback(t_env *e, t_obj *obj)
{
	t_obj	*obje;

	if (!ft_strcmp(obj->ref, "light"))
		obje = e->light;
	else
		obje = e->obj;
	if (obje)
	{
		while (obje->next)
			obje = obje->next;
		obje->next = objnew(obj);
	}
	else
		e->obj = objnew(obj);
}

static void		set_var(char *var, char *val, t_obj *obj)
{
	char			**tmp;

	if (!ft_strcmp(var, "object"))
		obj->ref = val;
	if (!ft_strcmp(var, "pos"))
	{
		tmp = ft_strsplit(val, ' ');
		obj->pos.x = (float)ft_atoi(tmp[0]);
		obj->pos.y = (float)ft_atoi(tmp[1]);
		obj->pos.z = (float)ft_atoi(tmp[2]);
		if (!ft_strcmp(obj->ref, "cylinder") || !ft_strcmp(obj->ref, "cone"))
			ft_invvec3(obj);
	}
	if (!ft_strcmp(var, "color"))
	{
		tmp = ft_strsplit(val, ' ');
		obj->color.x = (float)ft_atoi(tmp[0]);
		obj->color.y = (float)ft_atoi(tmp[1]);
		obj->color.z = (float)ft_atoi(tmp[2]);
	}
	if (!ft_strcmp(var, "size"))
		obj->size = ft_atoi(val);
	if (!ft_strcmp(var, "angle"))
		obj->angle = (float)tan((float)ft_atoi(val));
	if (!ft_strcmp(var, "n"))
	{
		tmp = ft_strsplit(val, ' ');
		obj->n.x = (float)ft_atoi(tmp[0]);
		obj->n.y = (float)ft_atoi(tmp[1]);
		obj->n.z = (float)ft_atoi(tmp[2]);
	}
}

static void		set_content(t_env *env, char *line)
{
	char			*var;
	char			*val;
	static t_obj	obj;

	(void)env;
	if (ft_strcmp(ft_strtrim(line), "{") && ft_strcmp(ft_strtrim(line), "}"))
	{
		var = get_info(line, &val);
		set_var(ft_strtrim(var), val, &obj);
	}
	if (!ft_strcmp(ft_strtrim(line), "}"))
			objpushback(env, &obj);
}

void			init_content(t_env *env, char *filename)
{
	int		fd;
	int		content;
	char	*line;

	content = 0;
	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		while (get_next_line(fd, &line))
		{
			if (content == 2 && !ft_strcmp(line, "]"))
				content = 3;
			if (content == 2)
				set_content(env, line);
			if (!ft_strcmp(line, "content"))
				content = 1;
			if (content && !ft_strcmp(line, "["))
				content = 2;
		}
		close(fd);
		free(line);
	}
}
