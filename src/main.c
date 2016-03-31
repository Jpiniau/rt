/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:22:26 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/31 16:51:34 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_get_data(t_env *e)
{
	int		bpp;
	int		sizeline;
	int		endian;

	e->data = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	e->data_img.bpp = bpp;
	e->data_img.sizeline = sizeline;
	e->data_img.endian = endian;
}

static int		ft_key_hook(int keycode, t_env *env) //static
{
	(void)env;
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	affich_obj(t_env env)
{
	t_obj	*obje;

	obje = env.obj;
	while (obje)
	{
		ft_putendl(obje->ref);
		obje = obje->next;
	}
}

static void		ft_init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->height, env->width, env->name);
	env->img = mlx_new_image(env->mlx, env->height, env->width);
}

int				main(int ac, char **av)
{
	t_env	env;

	(void)ac;
	init_env(&env, av[1]);
	init_content(&env, av[1]);
	ft_init_mlx(&env);
	ft_get_data(&env);
	scene(&env);
	mlx_key_hook(env.win, ft_key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
