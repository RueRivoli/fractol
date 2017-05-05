/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:20:36 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 19:22:24 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		value_x(t_env *env, int x)
{
	return (env->x_init + ((env->x_fin - env->x_init) * x / FENE_X) + \
			env->zoom->x_translation * ((env->x_fin - env->x_init) / 20));
}

float		value_y(t_env *env, int y)
{
	return (env->y_init + ((env->y_fin - env->y_init) * y / FENE_Y) + \
			env->zoom->y_translation * ((env->y_fin - env->y_init) / 20));
}

t_node		*init_node(void)
{
	t_node		*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->re_z = 0.0;
	node->im_z = 0.0;
	return (node);
}

void		modify_coord(t_env *env)
{
	float		m;
	float		n;

	if (env->zoom->x_zoom > 0)
		m = value_x(env, env->zoom->x_zoom);
	else
		m = 0;
	env->x_init = ((env->x_init - m) / env->zoom->zoom) + m;
	env->x_fin = ((env->x_fin - m) / env->zoom->zoom) + m;
	if (env->zoom->y_zoom > 0)
		n = value_y(env, env->zoom->y_zoom);
	else
		n = 0;
	env->y_init = ((env->y_init - n) / env->zoom->zoom) + n;
	env->y_fin = ((env->y_fin - n) / env->zoom->zoom) + n;
}

