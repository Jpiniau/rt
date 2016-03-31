/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:27:34 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/31 18:40:18 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"

typedef struct			s_3int
{
	int					x;
	int					y;
	int					z;
}						t_3int;

typedef struct			s_data_img
{
	int					bpp;
	int					sizeline;
	int					endian;
}						t_data_img;

typedef struct			s_obj
{
	t_3int				pos;
	t_3int				rot;
	t_3int				color;
	double				size;
	double				power;
	char				*ref;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	t_data_img			data_img;
	char				*data;
	int					height;
	int					width;
	t_3int				cam_pos;
	t_3int				cam_dir;
	t_obj				*obj;
	char				*name;
}						t_env;

void					init_env(t_env *env, char *filename);
void					init_content(t_env *env, char *filename);
char					*get_info(char *line, char **dst);
int						gnlv(char *src, char **line);
t_obj					*intersect(t_env *env, t_obj *obj, int x, int y);
float					intersect_circle(t_env *env, t_obj *circle, int x, int y);
int						scene(t_env *env);
int						ft_pixel_put(t_env *e, int x, int y,int color);

#endif
