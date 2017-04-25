/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:55:13 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/10 12:19:52 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		new_one(t_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->back_img = NULL;
	env->sup_img = NULL;
	env->church_img = NULL;
	env->map = NULL;
}

void		new_two(t_env *env)
{
	env->x = 0;
	env->y = 0;
	env->cte_x = 0;
	env->cte_y = 0;
	env->zoom = 1.0;
	env->x_zoom = -1;
	env->y_zoom = -1;
	env->x_init = 0;
	env->x_fin = 0;
	env->y_init = 0;
	env->y_fin = 0;
	env->prec_zoom = 0;
	env->prec_zoom = 0;
	env->x_pre_zoom = -1;
	env->y_pre_zoom = -1;
	env->x_translation = 0;
	env->y_translation = 0;
	env->alphax = 2.7 / FENE_X;
	env->x_0 = 0;
	env->y_0 = 0;
	env->alphay = 2.4 / FENE_Y;
	env->bool_color = 0;
	env->fractal_name = "";
}

t_env		*new_env(void)
{
	t_env *env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	new_one(env);
	new_two(env);
	return (env);
}

t_env		*init_env(char *av1)
{
	t_env	*env;
	int h;
	int w;

	h = HEIGHT_DRAW;
	w = WIDTH_DRAW;
	if (!(env = new_env()))
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, SIZE_X, SIZE_Y, "Fractol by fgallois");
	env->img = init_img(env, FENE_X, FENE_Y);
	env->back_img = init_img(env, SIZE_X, SIZE_Y);
	env->sup_img = init_img(env, SUPP_X, SUPP_Y);
	env->church_img = init_img(env, CHURCH, CHURCH);

	env->fractal_name = av1;
	initialise_coef(env);
	fill_img(env, &h, &w);
	return (env);
}
