/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:01:56 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 19:10:09 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**number 0 : translation to left
**number 1 : translation to down
**number 2 : translation to right
**number 3 : translation to up
*/

void		refresh(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	env->img = NULL;
	env->img = init_img(env, FENE_X, FENE_Y);
	trace(env);
	print_image_graph(env);
}

void		moovable(t_env *env)
{
	if (env->number == 1)
		env->moovable = 1;
}

void		change_iteration(t_env *env, int sign)
{
	if (sign == 1)
		env->zoom->iteration += 10;
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
