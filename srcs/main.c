/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:04:35 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/09 11:10:33 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*handle_error(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
	{
		error_param_no_conform();
		return (NULL);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0 && \
			ft_strcmp(argv[1], "julia") != 0 && ft_strcmp(argv[1], "bship") \
			!= 0 && ft_strcmp(argv[1], "chameleon") != 0 && \
		ft_strcmp(argv[1], "sword") != 0 && \
		ft_strcmp(argv[1], "celtic") != 0 && ft_strcmp(argv[1], "tricorn") \
		!= 0 && ft_strcmp(argv[1], "myfractal") != 0)
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

void		ft_free(t_env *env)
{
	free(env->fractal_name);
	free(env->zoom);
	free(env->man);
	free(env->jul);
	free(env);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	if (!(env = handle_error(argc, argv)))
		return (0);
	trace(env);
	print_all(env);
	ft_hook(env);
	ft_free(env);
	mlx_destroy_window(env->mlx, env->win);
	return (0);
}
