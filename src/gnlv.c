/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 19:35:09 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/20 21:19:39 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			gnlv(char *src, char **line)
{
	static size_t		i = 0;
	size_t		endl;

	endl = ft_strcchr(src + i, '\n');
	if ((int)endl == -1)
	{
		*line = ft_strnew(ft_strlen(src + i));
		*line = ft_strcpy(*line, src + i);
		return (-1);
	}
	endl += i;
	*line = ft_strnew(endl);
	*line = ft_strncpy(*line, src + i, endl);
	i = endl + 1;
	return (endl);
}
