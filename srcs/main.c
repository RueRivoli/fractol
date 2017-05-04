/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:04:35 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 20:24:58 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*handle_error(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
	{
		ft_putstr("usage: fractol [parameter (mandelbrot, julia or bship)]\n");
		return (NULL);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0 && \
			ft_strcmp(argv[1], "julia") && ft_strcmp(argv[1], "bship") != 0)
	{
		error_param_no_conform();
		return (NULL);
	}
	if (!(env = init_env(argv[1])))
	{
		error_no_image();
		return (NULL);
	}
	return (env);
}

void		ft_hook(t_env *env)
{
	mlx_key_hook(env->win, key_funct, &env->mlx);
	mlx_mouse_hook(env->win, &mouse_funct, &env->mlx);
	mlx_hook(env->win, 6, 1 << 8, mouse_funct_moovable, env);
	mlx_loop(env->mlx);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	if (!(env = handle_error(argc, argv)))
		return (0);
	trace(env);
	print_all(env);
	ft_hook(env);
	free(env);
	return (0);
}
