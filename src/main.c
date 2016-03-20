/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:22:26 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/20 21:29:41 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include "rt.h"

char *get_info(char *line, char **dst);

char	*get_scene(char	*file)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(ft_strstr(file, "scene\n["));
	i = ft_strcchr(tmp, ']') - 1;
	tmp = ft_strncpy(tmp, tmp, i);
	tmp = tmp + 8;
	return (tmp);
}

char	*get_content(char *file)
{
	char	*tmp;
	int		i;


	tmp = ft_strdup(ft_strstr(file, "content\n["));
	i = ft_strcchr(tmp, ']') - 1;
	tmp = ft_strncpy(tmp, tmp, i);	
	tmp = tmp + 10;
	return (tmp);

}

char	*get_file(char *filename)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	tmp = ft_strnew(0);
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd, &line))
		tmp = ft_strjoin3(tmp, line, "\n");
	close(fd);
	return (tmp);
}

int		main(int ac, char **av)
{
//	char	*scene;
//	char	*content;
//	char	*name;
	t_env	env;

	(void)ac;
	(void)av;
	//scene = get_scene(file);
	//ft_putendl(scene);
	//ft_putstr("\n");
	//content	= get_content(file);
	//ft_putendl(content);
	//name = get_info("name(bla bla bla)dfg", &content);
	//ft_putendl(name);
	//ft_putendl(content);
	init_env(&env, av[1]);
	return (0);
}
