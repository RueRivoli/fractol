/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:24:01 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 19:25:40 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			print_image_back(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, (env->back_img)->img, 0, 0);
}

void			print_image_supp(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, (env->sup_img)->img, 320, 80);
}

void			print_image_graph(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, (env->img)->img, 360, 100);
}

void			print_image_sign(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, \
			(env->church_img)->img, 30, 750);
}

void			print_all(t_env *env)
{
	print_image_back(env);
	print_image_sign(env);
	print_image_supp(env);
	print_image_graph(env);
	print_menu(env);
	print_title(env);
}
