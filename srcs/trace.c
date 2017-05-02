/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:09:54 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/01 18:18:49 by fgallois         ###   ########.fr       */
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
	t_zoom *zoom;

	zoom = env->zoom;
	modify_coord(env);
	x = 0;
	while (x < FENE_X)
	{
		y = 0;
		while (y < FENE_Y)
		{
			re_cte = env->jul->re_cte;/*0.285*/
			im_cte = env->jul->im_cte;/*0.01*/

			re_z = env->x_init + (env->x_fin - env->x_init) * x / FENE_X;
			im_z = env->y_init + (env->y_fin - env->y_init) * y / FENE_Y;
			re_z = re_z + zoom->x_translation * ((env->x_fin - env->x_init) / 20);
			im_z = im_z + zoom->y_translation * ((env->y_fin - env->y_init) / 20);
			
			i = 0;

			while (re_z * re_z + im_z * im_z < 4 && i < env->zoom->iteration)
			{
				mem = re_z;
				re_z = re_z * re_z - im_z * im_z + re_cte;
				im_z = 2 * im_z * mem + im_cte;
				i++;
			}
			if (i == zoom->iteration)
			{
				str = rgb_to_pchar(env, zoom->iteration, zoom->iteration, zoom->iteration);
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

/*void 	initialise_coef(t_env *env)
{
	if (ft_strcmp(env->fractal_name, "mandelbrot") == 0 || \
	ft_strcmp(env->fractal_name, "Mandelbrot") == 0)
	{
		env->fractal_name = "mandelbrot";
	

		new_mandelbrot(env);
		new_zoom(env);
		
		
		

	}
	else if (ft_strcmp(env->fractal_name, "julia") == 0 || \
	ft_strcmp(env->fractal_name, "Julia") == 0)
	{
		env->fractal_name = "julia";
		env->re_julia = 0.285;
		env->im_julia = 0.01;
		env->x_0 = -1.0;
		env->alphax = 2.0 / FENE_X;
		env->y_0 = -1.2;
	}
}*/



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
	t_zoom *zoom;

	zoom = env->zoom;
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
			re_cte = re_cte + zoom->x_translation * ((env->x_fin - env->x_init) / 20);
			im_cte = im_cte + zoom->y_translation * ((env->y_fin - env->y_init) / 20);
			re_z = 0;
			im_z = 0;
			i = 0;

			while (re_z * re_z + im_z * im_z < 4 && i < zoom->iteration)
			{
				mem = re_z;
				re_z = re_z * re_z - im_z * im_z + re_cte;
				im_z = 2 * im_z * mem + im_cte;
				i++;
			}
		
			if (i == zoom->iteration)
			{
				str = rgb_to_pchar(env, zoom->iteration, zoom->iteration, zoom->iteration);
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

