/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:55:13 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 19:38:32 by fgallois         ###   ########.fr       */
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
	env->x_init = 0;
	env->x_fin = 0;
	env->y_init = 0;
	env->y_fin = 0;
	env->moovable = 0;
	env->theme = BLUE;
}

t_env		*new_env(void)
{
	t_env	*env;

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

void		name(t_env *env, char *av1)
{
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
}

t_env		*init_env(char *av1)
{
	t_env	*env;
	int		h;
	int		w;

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
	name(env, av1);
	adapt_to_fractal(env);
	if (fill_img(env, &h, &w) == 0)
		return (NULL);
	return (env);
}
