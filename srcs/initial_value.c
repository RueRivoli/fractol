/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:18:39 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 19:20:20 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		new_mandelbrot(t_env *env)
{
	t_man	*man;
	t_zoom	*zoom;

	zoom = env->zoom;
	man = env->man;
	env->x_init = -2.5;
	env->x_fin = 1.2;
	env->y_fin = 1.5;
	env->y_init = -1.5;
	zoom->iteration = 50;
}

void		new_bship(t_env *env)
{
	t_man	*man;
	t_zoom	*zoom;

	zoom = env->zoom;
	man = env->man;
	env->x_init = -2.5;
	env->x_fin = 2.2;
	env->y_fin = 2.5;
	env->y_init = -2.5;
	zoom->iteration = 50;
}

void		new_julia(t_env *env)
{
	t_jul	*jul;
	t_zoom	*zoom;

	zoom = env->zoom;
	jul = env->jul;
	jul->re_cte = 0.285;
	jul->im_cte = 0.01;
	env->x_init = -1.8;
	env->x_fin = 1.8;
	env->y_fin = 1.7;
	env->y_init = -1.7;
	zoom->iteration = 150;
}

void		new_zoom(t_env *env)
{
	t_zoom	*zoom;

	zoom = env->zoom;
	zoom->x_translation = 0;
	zoom->y_translation = 0;
	zoom->zoom = 1.0;
	zoom->x_zoom = -1;
	zoom->y_zoom = -1;
	zoom->nb_zoom = 0;
	zoom->prec_zoom = 0;
	zoom->prec_dezoom = 0;
}

void		adapt_to_fractal(t_env *env)
{
	if (env->number == 0 || env->number == 5 || env->number == 6)
	{
		new_mandelbrot(env);
		new_zoom(env);
		env->zoom->iteration = 50;
	}
	else if (env->number == 1 || env->number == 3 || \
	env->number == 4 || env->number == 7)
	{
		new_julia(env);
		new_zoom(env);
		env->zoom->iteration = 50;
	}
	else if (env->number == 2)
	{
		new_bship(env);
		new_zoom(env);
		env->zoom->iteration = 50;
	}
}
