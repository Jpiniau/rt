/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:27:34 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/22 17:45:40 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"

# define AMB (0.2)

typedef struct			s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct			s_data_img
{
	int					bpp;
	int					sizeline;
	int					endian;
}						t_data_img;

typedef struct			s_ray
{
	t_vec3				o;
	t_vec3				d;
}						t_ray;

typedef struct			s_light
{
	t_vec3				pos;
	struct s_light		*next;
}						t_light;

typedef struct			s_obj
{
	t_vec3				pos;
	t_vec3				n;
	t_vec3				color;
	float				size;
	float				power;
	float				angle;
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
	float				height;
	float				width;
	t_vec3				cam_pos;
	t_vec3				cam_dir;
	t_obj				*obj;
	char				*name;
}						t_env;

void					init_env(t_env *env, char *filename);
void					init_content(t_env *env, char *filename);
void					init_vec3(t_vec3 *v, float x, float y, float z);
void					init_ray(t_ray *ray, int x, int y, t_env *env);
void					init_shadow_ray(t_ray *ray, t_vec3 light, t_vec3 point);
char					*get_info(char *line, char **dst);
int						get_normal(t_vec3 *normal, t_obj *obj, t_vec3 *point, t_ray *ray);
int						gnlv(char *src, char **line);
t_obj					*intersect(t_ray *ray, t_obj *obj, t_vec3 *point);
float					intersect_circle(t_ray *ray, t_obj *circle);
float					intersect_plane(t_ray *ray, t_obj *plane);
float					intersect_cylinder(t_ray *ray, t_obj *cylinder);
float					intersect_cone(t_ray *ray, t_obj *cone);
float					intersect_point(float a, float b, float delta);
t_obj					*intersect_shadow(t_ray *ray, t_obj *obj, t_light *light);
float					intersect_light(t_vec3 point, t_ray *ray, t_obj *obj, t_light light);
int						scene(t_env *env);
int						ft_pixel_put(t_env *e, int x, int y,int color);
float					distance(t_vec3 *a);
void					normalize(t_vec3 *a);
float					dot_product(t_vec3 *a, t_vec3 *b);
void					add_vec3(t_vec3 *a, t_vec3 *b, t_vec3 *c);
void					sus_vec3(t_vec3 *a, t_vec3 *b, t_vec3 *c);

#endif
