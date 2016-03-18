/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:25:14 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/18 18:50:31 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_info(char *line, char **dst)
{
	char	*name;
	int		in;
	int		out;

	in = ft_strcchr(line, '(');
	out = ft_strcchr(line, ')');
	name = ft_strndup(line, in);
	*dst = ft_strndup(line + in + 1, out - in - 1);
	return (name);
}
