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
	env->fractal_name = "";
	env->map = NULL;
	env->zoom = NULL;
	env->jul = NULL;
	env->man = NULL;
}


/*void		new_two(t_env *env)
{
	env->x = 0;
	env->y = 0;
	env->re_julia = 0.0;
	env->im_julia = 0.0;
	env->cte_x = 0;
	env->cte_y = 0;
	
	env->x_init = 0;
	env->x_fin = 0;
	env->y_init = 0;
	env->y_fin = 0;

	/*env->zoom = 1.0;
	env->x_zoom = -1;
	env->y_zoom = -1;
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
}*/

t_env		*new_env(void)
{
	t_env *env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	new_one(env);
	//new_two(env);
	return (env);
}

void		new_mandelbrot(t_env *env)
{
	t_man *man;

	man = env->man;
	zoom = env->zoom;
	man->x_0 = -2.1;
	man->alphax = 2.7 / FENE_X;
	man->y_0 = -1.2;
	man->x_init = -2.1;
	man->x_fin = 0.6;
	man->y_fin = 1.2;
	man->y_init = -1.2;
	man->alphay = 2.4 / FENE_Y;

	
}


void		new_julia(t_env *env)
{
	t_man *jul;
	
	jul->re_julia = 0.285;
	jul->im_julia = 0.01;
	jul->x_0 = -1.0;
	jul->alphax = 2.0 / FENE_X;
	jul->y_0 = -1.2;
	jul->x_init = -1.0;
	jul->x_fin = 1.0;
	jul->y_fin = 1.2;
	jul->y_init = -1.2;
	jul->iteration = 150;
	jul->alphay = 2.4 / FENE_Y;
}

void	new_zoom(t_env *env)
{
	t_zoom *zoom;

	zoom = env->zoom;
	zoom->x_translation = 0;
	zoom->y_translation = 0;
	zoom->zoom = 1;
	zoom->x_zoom = 0;
	zoom->y_zoom = 0;
	zoom->x_pre_zoom = 0;
	zoom->y_pre_zoom = 0;
	zoom->prec_zoom = 0;
	zoom->prec_dezoom = 0;
}

void		adapt_to_fractal(t_env *env, char *av)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
			new_mandelbrot(env);
			new_zoom(env);
			env->zoom->iteration = 50;
	}
	else if  (ft_strcmp(argv[1], "julia") == 0)
	{
			new_julia(env);
			new_zoom(env);
			env->zoom->iteration = 150;
	}
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
