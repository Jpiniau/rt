/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:40:01 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/18 15:50:33 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin3(char const *s1, char const *s2, char *s3)
{
	char	*new_str;

	if (!s1 && !s2 && !s3)
		return (NULL);
	else if (!s1)
		return (ft_strjoin(s2, s3));
	else if (!s2)
		return (ft_strjoin(s1, s3));
	else if (!s3)
		return (ft_strjoin(s1, s2));
	new_str = ft_strjoin(s1, s2);
	new_str = ft_strjoin(new_str, (char const *)s3);
	return (new_str);
}
