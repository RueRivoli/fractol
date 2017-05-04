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
	env->number = 0;
	env->fractal_name = "";
	env->map = NULL;
	env->x_init = 0;
	env->x_fin = 0;
	env->y_init = 0;
	env->y_fin = 0;
	env->moovable = 0;
	env->theme = BLUE;
}

t_env		*new_env(void)
{
	t_env *env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	if (!(env->jul = (t_jul*)malloc(sizeof(t_jul))))
		return (NULL);
	if (!(env->man = (t_man*)malloc(sizeof(t_man))))
		return (NULL);
	if (!(env->zoom = (t_zoom*)malloc(sizeof(t_zoom))))
		return (NULL);
	if (!(env->fractal_name = (char*)malloc(sizeof(char))))
		return (NULL);	
	new_one(env);
	return (env);
}

void		new_mandelbrot(t_env *env)
{
	t_man *man;
	t_zoom *zoom;

	zoom = env->zoom;
	man = env->man;
	env->x_init = -2.5;
	env->x_fin = 1.2;
	env->y_fin = 1.5;
	env->y_init = -1.5;
	zoom->iteration = 50;
}


void		new_julia(t_env *env)
{
	t_jul *jul;
	t_zoom *zoom;

	zoom = env->zoom;	
	jul = env->jul;
	jul->re_cte = 0.285;
	jul->im_cte = 0.01;
	env->x_init = -1.8;
	env->x_fin = 1.8;
	env->y_fin = 1.7;
	env->y_init = -1.7;
	zoom->iteration = 50;
	env->number = 1;
}

void	new_zoom(t_env *env)
{
	t_zoom *zoom;

	zoom = env->zoom;
	zoom->x_translation = 0;
	zoom->y_translation = 0;
	zoom->zoom = 1.0;
	zoom->x_zoom = -1;
	zoom->y_zoom = -1;
	zoom->nb_zoom = 0;
	zoom->prec_zoom = 0;
	zoom->prec_dezoom = 0;
}

void		adapt_to_fractal(t_env *env)
{
	
	if (env->number == 0 || env->number == 2)
	{
			new_mandelbrot(env);
			new_zoom(env);
			env->zoom->iteration = 50;
	}
	else if  (env->number == 1)
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
	if (ft_strcmp(av1, "mandelbrot") == 0)
	{
		env->number = 0;
		env->fractal_name = "Mandelbrot";
	}
	if (ft_strcmp(av1, "julia") == 0)
	{
		env->number = 1;
		env->fractal_name = "Julia";
	}
	if (ft_strcmp(av1, "bship") == 0)
	{
		env->number = 2;
		env->fractal_name = "Bship";
	}
	adapt_to_fractal(env);
	fill_img(env, &h, &w);
	return (env);
}
