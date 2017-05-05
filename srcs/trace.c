/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:09:54 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 19:35:51 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		convergence_mandelbrot(t_env *env, t_node *node, int x, int y)
{
	int			iteration;
	float		im_cte;
	float		re_cte;

	iteration = 0;
	node->re_z = 0.0;
	node->im_z = 0.0;
	re_cte = env->x_init + (env->x_fin - env->x_init) * x / FENE_X;
	im_cte = env->y_init + (env->y_fin - env->y_init) * y / FENE_Y;
	re_cte += env->zoom->x_translation * ((env->x_fin - env->x_init) / 20);
	im_cte += env->zoom->y_translation * ((env->y_fin - env->y_init) / 20);
	while (node->re_z * node->re_z + node->im_z * node->im_z < 4 \
			&& iteration < env->zoom->iteration)
	{
		apply_sequence_man(env, node, re_cte, im_cte);
		iteration++;
	}
	if (iteration == env->zoom->iteration)
		mlx_put_pixel_to_image(env, x, y, iteration);
	else
		mlx_put_pixel_to_image(env, x, y, iteration);
}

void		trace_mandelbrot(t_env *env)
{
	int		x;
	int		y;
	t_node	*node;

	x = 0;
	node = init_node();
	modify_coord(env);
	while (x < FENE_X)
	{
		y = 0;
		while (y < FENE_Y)
		{
			convergence_mandelbrot(env, node, x, y);
			y++;
		}
		x++;
	}
	free(node);
}



void		convergence_julia(t_env *env, t_node *node, int x, int y)
{
	float		re_cte;
	float		im_cte;
	int			iteration;

	re_cte = env->jul->re_cte;
	im_cte = env->jul->im_cte;
	iteration = 0;
	node->re_z = env->x_init + (env->x_fin - env->x_init) * x / FENE_X;
	node->im_z = env->y_init + (env->y_fin - env->y_init) * y / FENE_Y;
	node->re_z = node->re_z + env->zoom->x_translation * \
				((env->x_fin - env->x_init) / 20);
	node->im_z = node->im_z + env->zoom->y_translation * \
				((env->y_fin - env->y_init) / 20);
	iteration = 0;
	while (node->re_z * node->re_z + node->im_z * node->im_z < 4 \
			&& iteration < env->zoom->iteration)
	{
		apply_sequence_jul(env, node, re_cte, im_cte);
		iteration++;
	}
	if (iteration == env->zoom->iteration)
		mlx_put_pixel_to_image(env, x, y, iteration);
	else
		mlx_put_pixel_to_image(env, x, y, iteration);
}

void		trace_julia(t_env *env)
{
	int		x;
	int		y;
	t_zoom	*zoom;
	t_node	*node;

	zoom = env->zoom;
	modify_coord(env);
	x = 0;
	node = init_node();
	while (x < FENE_X)
	{
		y = 0;
		while (y < FENE_Y)
		{
			convergence_julia(env, node, x, y);
			y++;
		}
		x++;
	}
	free(node);
}

void		trace(t_env *env)
{
	if (env->number == 0 || env->number == 2 || env->number == 5 || env->number == 6)
		trace_mandelbrot(env);
	if (env->number == 1 || env->number == 3 || env->number == 4 || env->number == 7)
		trace_julia(env);
}
