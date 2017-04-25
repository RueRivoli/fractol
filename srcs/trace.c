/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:09:54 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/10 13:40:37 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		trace_julia(t_env *env)
{
	int x;
	int y;
	float re_z;
	float im_z;
	float mem;
	int i;
	float im_cte;
	float re_cte;
	char *str;
	str = NULL;

	modify_coord(env);
	x = 0;
	while (x < FENE_X)
	{
		y = 0;
		while (y < FENE_Y)
		{
			re_cte = 0.285;
			im_cte = 0.01;

			re_z = env->x_init + (env->x_fin - env->x_init) * x / FENE_X;
			im_z = env->y_init + (env->y_fin - env->y_init) * y / FENE_Y;
			re_z = re_z + env->x_translation * ((env->x_fin - env->x_init) / 20);
			im_z = im_z + env->y_translation * ((env->y_fin - env->y_init) / 20);
			
			i = 0;

			while (re_z * re_z + im_z * im_z < 4 && i < env->iteration)
			{
				mem = re_z;
				re_z = re_z * re_z - im_z * im_z + re_cte;
				im_z = 2 * im_z * mem + im_cte;
				i++;
			}
			if (i == env->iteration)
			{
				str = rgb_to_pchar(env, env->iteration, env->iteration, env->iteration);
				mlx_put_pixel_to_imagei(env, x, y, get_color(str));
				free(str);
			}
			else
			{
				str = rgb_to_pchar(env, 0, 0, i);
				mlx_put_pixel_to_imagei(env, x, y, get_color(str));
				free(str);
			}
			y++;
		}
		x++;
	}
}

void 	initialise_coef(t_env *env)
{
	if (ft_strcmp(env->fractal_name, "mandelbrot") == 0 || \
	ft_strcmp(env->fractal_name, "Mandelbrot") == 0)
	{
		env->fractal_name = "mandelbrot";
		env->x_0 = -2.1;
		env->alphax = 2.7 / FENE_X;
		env->y_0 = -1.2;
		env->x_init = -2.1;
		env->x_fin = 0.6;
		env->x_translation = 0;
		env->y_translation = 0;
		env->y_fin = 1.2;
		env->y_init = -1.2;
		env->iteration = 50;
		env->alphay = 2.4 / FENE_Y;
	}
	else if (ft_strcmp(env->fractal_name, "julia") == 0 || \
	ft_strcmp(env->fractal_name, "Julia") == 0)
	{
		env->fractal_name = "julia";
		env->x_0 = -1.0;
		env->alphax = 2.0 / FENE_X;
		env->y_0 = -1.2;
		env->x_init = -1.0;
		env->x_fin = 1.0;
		env->x_translation = 0;
		env->y_translation = 0;
		env->y_fin = 1.2;
		env->y_init = -1.2;
		env->iteration = 150;
		env->alphay = 2.4 / FENE_Y;
	}
}



void		trace_mandelbrot(t_env *env)
{
	int x;
	int y;
	float re_z;
	float im_z;
	float mem;
	int i;
	float im_cte;
	float re_cte;
	char *str;
	str = NULL;
	x = 0;
	modify_coord(env);
	while (x < FENE_X)
	{
		y = 0;
		while (y < FENE_Y)
		{
			
			re_cte = env->x_init + (env->x_fin - env->x_init) * x / FENE_X;
			im_cte = env->y_init + (env->y_fin - env->y_init) * y / FENE_Y;
			re_cte = re_cte + env->x_translation * ((env->x_fin - env->x_init) / 20);
			im_cte = im_cte + env->y_translation * ((env->y_fin - env->y_init) / 20);
			re_z = 0;
			im_z = 0;
			i = 0;

			while (re_z * re_z + im_z * im_z < 4 && i < env->iteration)
			{
				mem = re_z;
				re_z = re_z * re_z - im_z * im_z + re_cte;
				im_z = 2 * im_z * mem + im_cte;
				i++;
			}
		
			if (i == env->iteration)
			{
				str = rgb_to_pchar(env, env->iteration, env->iteration, env->iteration);
				//str = "0xFF0000";
				//mlx_put_pixel_to_imagec(env, x, y, str);
				mlx_put_pixel_to_imagei(env, x, y, get_color(str));
				free(str);
			}
			else
			{
				str = rgb_to_pchar(env, 0, 0, i);
				mlx_put_pixel_to_imagei(env, x, y, get_color(str));
				free(str);
			}
			y++;
		}
		x++;
	}
}

