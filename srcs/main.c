/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:04:35 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/10 12:58:48 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
char		*get_file_name(char *av1)
{
	char *st;

	st = NULL;
	if (ft_ispresent(av1, '/') == 1)
	{
		st = ft_strrchr(av1, '/');
		st++;
	}
	else
		st = av1;
	return (ft_strsub(st, 0, ft_strlen(st) - 4));
}*/

t_env		*handle_error(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
	{
		ft_putstr("usage: fractol [parameter (mandelbrot or julia)]\n");
		return (NULL);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0  && ft_strcmp(argv[1], "julia") != 0)
	{
		error_param_no_conform();
		return (NULL);
	}
	if (!(env = init_env(argv[1])))
		return (NULL);
	return (env);
}

void		ft_hook(t_env *env)
{
	mlx_key_hook(env->win, key_funct, &env->mlx);
	mlx_mouse_hook(env->win, &mouse_funct, &env->mlx);
	mlx_loop(env->mlx);
}

int			main(int argc, char **argv)
{
	t_env *env;
	
	if (!(env = handle_error(argc, argv)))
		return (0);
		
	//ft_hook(env);
	//initialise_coef(env);
	
	trace(env);
	//mlx_expose_hook(env->win, &print_title, &env->mlx);
	//ft_putstr("Savate");
	print_all(env);
	
	ft_hook(env);
	
	return (0);
}
