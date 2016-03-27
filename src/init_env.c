/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:58:15 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/27 16:02:58 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_var(t_env *env, char *var, char *val)
{
	char	**tmp;

	if (!ft_strcmp(var, "name"))
	{
		env->name = ft_strdup(val);
	}
	if (!ft_strcmp(var, "cam_pos"))
	{
		tmp = ft_strsplit(val, ' ');
		env->cam_pos.x = ft_atoi(tmp[0]);
		env->cam_pos.y = ft_atoi(tmp[1]);
		env->cam_pos.z = ft_atoi(tmp[2]);
	}
	if (!ft_strcmp(var, "cam_dir"))
	{
		tmp = ft_strsplit(val, ' ');
		env->cam_dir.x = ft_atoi(tmp[0]);
		env->cam_dir.y = ft_atoi(tmp[1]);
		env->cam_dir.z = ft_atoi(tmp[2]);
	}
	if (!ft_strcmp(var, "render"))
	{
		tmp = ft_strsplit(val, ' ');
		env->height = ft_atoi(tmp[0]);
		env->width = ft_atoi(tmp[1]);
	}
}

static void		set_scene(t_env *env, char *line)
{
	char	*var;
	char	*val;

	var = get_info(line, &val);
	set_var(env, ft_strtrim(var), val);
}

void			init_env(t_env *env, char *filename)
{
	int		fd;
	int 	scene;
	char	*line;

	scene = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) && scene != 3)
	{
		if (scene == 2 && !ft_strcmp(line, "]"))
			scene = 3;
		if (scene == 2)
			set_scene(env, line);
		if (!ft_strcmp(line, "scene"))
			scene = 1;
		if (scene && !ft_strcmp(line, "["))
			scene = 2;
	}
	if (scene != 3)
	{
		ft_putendl("NO SCENE!!");
		exit(1);
	}
	close(fd);
}
