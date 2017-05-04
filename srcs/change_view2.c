/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_view2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:10:27 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 19:11:29 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		translation(t_env *env, int i)
{
	t_zoom	*zoom;

	zoom = env->zoom;
	zoom->x_zoom = 0;
	zoom->y_zoom = 0;
	zoom->prec_zoom = 0;
	zoom->prec_dezoom = 0;
	zoom->zoom = 1.0;
	if (i == 0)
		zoom->x_translation++;
	else if (i == 1)
		zoom->y_translation--;
	else if (i == 2)
		zoom->x_translation--;
	else if (i == 3)
		zoom->y_translation++;
	refresh(env);
}

void		restart(t_env *env)
{
	env->theme = BLUE;
	adapt_to_fractal(env);
	refresh(env);
}

float		power(int nb_zoom, float num)
{
	float	res;

	res = 1.0;
	while (nb_zoom > 0)
	{
		res = num * res;
		nb_zoom--;
	}
	return (res);
}

void		zoom(t_env *env, int x, int y)
{
	t_zoom *zoom;

	zoom = env->zoom;
	if (zoom->prec_dezoom == 1)
		zoom->nb_zoom = 1;
	else
		zoom->nb_zoom++;
	zoom->zoom = power(zoom->nb_zoom, 1.01);
	zoom->x_zoom = x;
	zoom->y_zoom = y;
	refresh(env);
	zoom->zoom = 1;
	zoom->prec_dezoom = 0;
	zoom->prec_zoom = 1;
}

void		dezoom(t_env *env, int x, int y)
{
	t_zoom *zoom;

	zoom = env->zoom;
	if (zoom->prec_zoom == 1)
		zoom->nb_zoom = -1;
	else
		zoom->nb_zoom--;
	zoom->zoom = power(-zoom->nb_zoom, 0.95);
	zoom->x_zoom = x;
	zoom->y_zoom = y;
	refresh(env);
	zoom->zoom = 1;
	zoom->prec_dezoom = 1;
	zoom->prec_zoom = 0;
}
