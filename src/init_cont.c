/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:41:02 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/26 18:11:07 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	*objnew(t_obj *obj)
{
	t_obj	*ret;

	ret = (t_obj *)malloc(sizeof(t_obj));
	ret->size = obj->size;
	ret->power = obj->power;
	ret->ref = obj->ref;
	ret->pos = obj->pos;
	ret->rot = obj->rot;
	ret->color = obj->color;
	return (ret);
}

void	objpushback(t_env *e, t_obj *obj)
{
	t_obj	*obje;

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
		obj->pos.x = ft_atoi(tmp[0]);
		obj->pos.y = ft_atoi(tmp[1]);
		obj->pos.z = ft_atoi(tmp[2]);
	}
	if (!ft_strcmp(var, "color"))
	{
		tmp = ft_strsplit(val, ' ');
		obj->color.x = ft_atoi(tmp[0]);
		obj->color.y = ft_atoi(tmp[1]);
		obj->color.z = ft_atoi(tmp[2]);
	}
	if (!ft_strcmp(var, "size"))
	{
		obj->size = ft_atoi(val);
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
