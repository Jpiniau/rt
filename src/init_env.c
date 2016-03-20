/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:58:15 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/20 21:28:45 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include "rt.h"

static void		set_scene(t_env *env, char *scene)
{
	char	*line;
	char	*var;
	char	*val;

	(void)env;
	while(gnlv(scene, &line) != -1)
	{
		var = get_info(line, &val);
		ft_putchar('\n');
		ft_putstr("name :");
		ft_putendl(var);
		ft_putstr("valeur :");
		ft_putendl(val);
		//set_var(env, name, val);
	}
	var = get_info(line, &val);
	ft_putchar('\n');
	ft_putstr("name :");
	ft_putendl(var);
	ft_putstr("valeur :");
	ft_putendl(val);
	//set_var(env, name, val);
}

static void		get_scene(char *file, char **scene)
{
	int		i;

	*scene = ft_strdup(ft_strstr(file, "scene\n["));
	i = ft_strcchr(*scene, ']') - 1;
	*scene = ft_strncpy(*scene, *scene, i);
	*scene = *scene + 8;
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

void	init_env(t_env *env, char *filename)
{
	char *file;
	char *scene;

	(void)env;
	get_file(filename, &file);
	get_scene(file, &scene);
	set_scene(env, scene);
}
