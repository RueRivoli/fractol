/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:01:56 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/10 15:08:25 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**number 0 : translation to left
**number 1 : translation to down
**number 2 : translation to right
**number 3 : translation to up
*/

void	refresh(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
    env->img = NULL;
    env->img = init_img(env, FENE_X, FENE_Y);
    trace(env);
    print_image_graph(env);
}

void	moovable(t_env *env)
{
	if (env->number == 1)
		env->moovable = 1;
}

void	change_iteration(t_env *env, int sign)
{
	if (sign == 1)
		env->zoom->iteration +=10;
	else if (sign == 0)
	{
		if (env->zoom->iteration > 10)
			env->zoom->iteration -= 10;
	}	
	refresh(env);
}

void		change_color(t_env *env, int color)
{
	env->theme = color;
	refresh(env);
}

void	 translation(t_env *env, int i)
{
	t_zoom *zoom;

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

void	restart(t_env *env)
{
	adapt_to_fractal(env);
	refresh(env);
}

float		power(int nb_zoom, float num)
{
	float res;
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
