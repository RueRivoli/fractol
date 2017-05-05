/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:25:46 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 19:26:14 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			print_menu(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 1700, 115, 0xd6b017, " M E N U ");
	mlx_string_put(env->mlx, env->win, 1650, 200, \
			0xD3D3DA, "Couleurs : R P B Y G");
	mlx_string_put(env->mlx, env->win, 1650, 250, 0xD3D3DA,\
			"Rendre modulable : M");
	mlx_string_put(env->mlx, env->win, 1650, 300, 0xD3D3DA,\
			"Translater : fleches");
	mlx_string_put(env->mlx, env->win, 1650, 350, 0xD3D3DA,\
			"Start : O");
	mlx_string_put(env->mlx, env->win, 1650, 400, 0xD3D3DA,\
			"Augmenter iteration : +");
	mlx_string_put(env->mlx, env->win, 1650, 450, 0xD3D3DA,\
			"Diminuer iteration : -");
	mlx_string_put(env->mlx, env->win, 1650, 500, 0xD3D3DA,\
			"Zoom : scroll arriere");
	mlx_string_put(env->mlx, env->win, 1650, 550, 0xD3D3DA,\
			"Dezoom : scroll avant");
	return (0);
}

int			print_title(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 880, 30, 0xd6b017, env->fractal_name);
	mlx_string_put(env->mlx, env->win, 30, 600, 0xFB9800, \
			" \"Success consists of going");
	mlx_string_put(env->mlx, env->win, 30, 650, 0xFB9800,\
			" from failure to failure ");
	mlx_string_put(env->mlx, env->win, 30, 700, 0xFB9800,\
			" without loss of enthusiasm\"");
	mlx_string_put(env->mlx, env->win, 30, 1030, 0x3A5FCD,\
			"http://github.com/RueRivoli");
	return (1);
}

void		apply_sequence_jul(t_env *env, t_node *node, float re_cte, float im_cte)
{
	if (env->number == 1)
			sequence_julia(node, re_cte, im_cte);
	else if (env->number == 3)
			sequence_chameleon(node, re_cte, im_cte);
	else if (env->number == 4)
			sequence_sword(node, re_cte, im_cte);
	else if (env->number == 7)
			sequence_myfractal(node, re_cte, im_cte);
}

void		apply_sequence_man(t_env *env, t_node *node, float re_cte, float im_cte)
{
		if (env->number == 0)
			sequence_mandelbrot(node, re_cte, im_cte);
		else if (env->number == 2)
			sequence_bship(node, re_cte, im_cte);
		else if (env->number == 5)
			sequence_celtic(node, re_cte, im_cte);
		else if (env->number == 6)
			sequence_tricorn(node, re_cte, im_cte);
}

