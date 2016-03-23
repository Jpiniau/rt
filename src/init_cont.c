/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:41:02 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/23 19:14:06 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_var(t_env *env, char *var, char *val)
{
	char	**tmp;

	if (!ft_strcmp(var, "name"))
		env->name = val;
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
	ft_putstr(var);
	ft_putstr(" : ");
	ft_putendl(val);
}

static void		set_content(t_env *env, char *scene)
{
	char	*line;
	char	*var;
	char	*val;

	while(gnlv(scene, &line) != -1)
	{
		var = get_info(line, &val);
		set_var(env, ft_strtrim(var), val);
	}
	var = get_info(line, &val);
	set_var(env, ft_strtrim(var), val);
}

static void		get_content(char *file, char **content)
{
	int		i;


	*content = ft_strdup(ft_strstr(file, "content\n["));
	i = ft_strcchr(*content, ']') - 1;
	*content = ft_strncpy(*content, *content, i);
	*content = *content + 10;
}

static void		get_file(char *filename, char **file)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	*file = ft_strnew(0);
	if (fd >= 0)
	{
		while (get_next_line(fd, &line))
			*file = ft_strjoin3(*file, line, "\n");
		close(fd);
		free(line);
	}
}

void	init_content(t_env *env, char *filename)
{
	char	*file;
	char	*content;
//	char	*obj;

	(void)env;
	get_file(filename, &file);
	get_content(file, &content);
	set_content(env, content);
//	get_one_obj(content, $obj);
//	set_obj(env, obj);
}
