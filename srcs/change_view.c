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
	env->x_zoom = 0;
	env->y_zoom = 0;
	env->prec_zoom = 0;
	env->prec_dezoom = 0;
	env->zoom = 1.0;
	
	if (i == 0)
	{
		env->x_translation++;
	}
	else if (i == 1)
	{
		env->y_translation--;
	}
	else if (i == 2)
	{
		env->x_translation--;
	}
	else if (i == 3)
	{	
		env->y_translation++;
	}
	refresh(env);
}

void	restart(t_env *env)
{
	initialise_coef(env);
	refresh(env);
}
void		zoom(t_env *env, int x, int y)
{	
	if (env->prec_zoom == 1)
		env->zoom = env->zoom * 1.05;
	else
		env->zoom = 1.01;
	if (env->zoom > 1.4)
		env->zoom = 1.2;
	env->prec_zoom = 1;
	env->prec_dezoom = 0;
	env->x_zoom = x;
	env->y_zoom = y;
	refresh(env);
}

void		dezoom(t_env *env, int x, int y)
{
	if (env->prec_dezoom == 1)
		env->zoom = env->zoom / 1.01;
	else
		env->zoom = 0.95;
	if (env->zoom < 0.8)
		env->zoom = 0.90;
	env->prec_dezoom = 1;
	env->prec_zoom = 0;
	env->x_zoom = x;
	env->y_zoom = y;
	refresh(env);
}
