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
	{
		zoom->x_translation++;
	}
	else if (i == 1)
	{
		zoom->y_translation--;
	}
	else if (i == 2)
	{
		zoom->x_translation--;
	}
	else if (i == 3)
	{	
		zoom->y_translation++;
	}
	refresh(env);
}

void	restart(t_env *env)
{
	adapt_to_fractal(env);
	refresh(env);
}
void		zoom(t_env *env, int x, int y)
{
	t_zoom *zoom;	

	zoom = env->zoom;
	if (zoom->prec_zoom == 1)
		zoom->zoom = zoom->zoom * 1.05;
	else
		zoom->zoom = 1.01;
	if (zoom->zoom > 1.4)
		zoom->zoom = 1.2;
	zoom->prec_zoom = 1;
	zoom->prec_dezoom = 0;
	zoom->x_zoom = x;
	zoom->y_zoom = y;
	refresh(env);
}

void		dezoom(t_env *env, int x, int y)
{
	t_zoom *zoom;	

	zoom = env->zoom;
	if (zoom->prec_dezoom == 1)
		zoom->zoom = zoom->zoom / 1.01;
	else
		zoom->zoom = 0.95;
	if (zoom->zoom < 0.8)
		zoom->zoom = 0.90;
	zoom->prec_dezoom = 1;
	zoom->prec_zoom = 0;
	zoom->x_zoom = x;
	zoom->y_zoom = y;
	refresh(env);
}
