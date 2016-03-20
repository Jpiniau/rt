/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:27:34 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/20 20:04:50 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

typedef struct			s_3int
{
	int					x;
	int					y;
	int					z;
}						t_3int;

typedef struct			s_obj
{
	t_3int				pos;
	t_3int				rot;
	t_3int				color;
	double				size;
	double				power;
	double				ref;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	int					height;
	int					width;
	t_3int				cam_pos;
	t_3int				cam_dir;
	t_obj				*obj;
	char				*screen_name;
}						t_env;

void					init_env(t_env *env, char *filename);
char					*get_info(char *line, char **dst);
int						gnlv(char *src, char **line);

#endif
