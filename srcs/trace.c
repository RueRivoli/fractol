/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:09:54 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/01 18:18:49 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		transform_mandelbrot(t_node *node, float re_cte, float im_cte)
{
	float mem;

	mem = node->re_z;
	node->re_z = node->re_z * node->re_z - node->im_z * node->im_z + re_cte;
	node->im_z = 2 * node->im_z * mem + im_cte;
}


void		transform_julia(t_node *node, float re_cte, float im_cte)
{
	float mem;

	mem = node->re_z;
	node->re_z = node->re_z * node->re_z - node->im_z * node->im_z + re_cte;
	node->im_z = 2 * node->im_z * mem + im_cte;
}

void		transform_bship(t_node *node, float re_cte, float im_cte)
{
	float mem;

	mem = node->re_z;
	node->re_z = fabsf(node->re_z * node->re_z) - fabsf(node->im_z * node->im_z) + re_cte;
	node->im_z = 2 * fabsf(node->im_z * mem) + im_cte;
}

void		formula_julia(t_env *env, t_node *node, int x, int y)
{
	t_zoom *zoom;
	float re_cte;
	float im_cte;
	int iteration;

	zoom = env->zoom;
	re_cte = env->jul->re_cte;
	im_cte = env->jul->im_cte;
	iteration = 0;
	node->re_z = 0.0;
	node->im_z = 0.0;
	node->re_z = env->x_init + (env->x_fin - env->x_init) * x / FENE_X;
	node->im_z = env->y_init + (env->y_fin - env->y_init) * y / FENE_Y;
	node->re_z = node->re_z + zoom->x_translation * ((env->x_fin - env->x_init) / 20);
	node->im_z = node->im_z + zoom->y_translation * ((env->y_fin - env->y_init) / 20);
	iteration = 0;
	while (node->re_z * node->re_z + node->im_z * node->im_z < 4 && iteration < env->zoom->iteration)
	{
		transform_julia(node, re_cte, im_cte);
		iteration++;
	}
	if (iteration == zoom->iteration)
			mlx_put_pixel_to_image(env, x, y, iteration);
	else
			mlx_put_pixel_to_image(env, x, y, iteration);
}

void		trace_julia(t_env *env)
{
	int x;
	int y;
	t_zoom *zoom;
	t_node *node;

	zoom = env->zoom;
	modify_coord(env);
	x = 0;
	node = init_node();
	while (x < FENE_X)
	{
		y = 0;
		while (y < FENE_Y)
		{
			formula_julia(env, node, x, y);
			y++;
		}
		x++;
	}
	free(node);
}


void		formula_mandelbrot(t_env *env, t_node *node, int x, int y)
{
	t_zoom *zoom;
	int iteration;
	float im_cte;
	float re_cte;

	iteration = 0;
	zoom = env->zoom;
			
	node->re_z = 0.0;
	node->im_z = 0.0;
	re_cte = env->x_init + (env->x_fin - env->x_init) * x / FENE_X;
	im_cte = env->y_init + (env->y_fin - env->y_init) * y / FENE_Y;
	re_cte = re_cte + zoom->x_translation * ((env->x_fin - env->x_init) / 20);
	im_cte = im_cte + zoom->y_translation * ((env->y_fin - env->y_init) / 20);
	
	while (node->re_z * node->re_z + node->im_z * node->im_z < 4 && iteration < zoom->iteration)
	{
		if (env->number == 0)
			transform_mandelbrot(node, re_cte, im_cte);
		else if (env->number == 2)
			transform_bship(node, re_cte, im_cte);
		iteration++;
	}
	if (iteration == zoom->iteration)
			mlx_put_pixel_to_image(env, x, y, iteration);
	else
			mlx_put_pixel_to_image(env, x, y, iteration);
}


void		trace_mandelbrot(t_env *env)
{
	int x;
	int y;
	t_node *node;

	x = 0;
	node = init_node();
	modify_coord(env);
	while (x < FENE_X)
	{
		y = 0;
		while (y < FENE_Y)
		{
			
			formula_mandelbrot(env, node, x, y);
			y++;
		}
		x++;
	}
	free(node);
}

