/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:11:09 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/06 17:13:34 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_put_pixel_to_image(t_env *env, int x, int y, int iteration)
{
	int		octet;
	int		color;

	octet = env->img->bpp / 8;
	color = env->theme * iteration / env->zoom->iteration;
	if (x >= 0 && y >= 0 && x < FENE_X && y < FENE_Y)
	{
		ft_memcpy(&env->img->data[octet * x + env->img->sizeline * \
	y], &color, octet);
	}
}

t_img		*init_img(t_env *env, int height, int width)
{
	t_img	*image;

	if (!(image = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	image->img = mlx_new_image(env->mlx, height, width);
	image->data = mlx_get_data_addr(image->img,\
	&image->bpp, &image->sizeline, &image->endian);
	return (image);
}

void		fill_img(t_env *env, int *h, int *w)
{
	env->back_img->img = mlx_xpm_file_to_image(env->mlx, \
			"images/planetpropre.xpm", w, h);
	env->church_img->img = mlx_xpm_file_to_image(env->mlx, \
			"images/church.xpm", w, h);
	env->sup_img->img = mlx_xpm_file_to_image(env->mlx, \
			"images/blancdim.XPM", w, h);
}
