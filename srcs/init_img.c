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

char    *rgb_to_pchar(t_env *env, int rn, int gn, int bn)
{
    char *hex;
    char *str;
	t_zoom *zoom;

	zoom = env->zoom;
    if (!(str = ft_strnew(8)))
        return (NULL);
    hex = NULL;
	hex = ft_itohex((int)rn * 255 / zoom->iteration);
    str[0] = '0';
    str[1] = 'x';
    str[2] = hex[0];
    str[3] = hex[1];
	free(hex);
	hex = NULL;
    hex = ft_itohex((int)gn * 255 / zoom->iteration);
    str[4] = hex[0];
    str[5] = hex[1];
	free(hex);
	hex = NULL;
    hex = ft_itohex((int)bn * 255 / zoom->iteration);
    str[6] = hex[0];
    str[7] = hex[1];
	free(hex);
	//ft_putstr(str);
    return (str);
}

void		mlx_put_pixel_to_imagec(t_env *env, int x, int y, char *str)
{
	int		octet;
	
	octet = env->img->bpp / 8;
	if (x >= 0 && y >= 0 && x < FENE_X && y < FENE_Y)
	{
		ft_memcpy(&env->img->data[octet * x + env->img->sizeline * \
	y], &str, octet);
	}
}

void		mlx_put_pixel_to_imagei(t_env *env, int x, int y, int a)
{
	int		octet;
	
	octet = env->img->bpp / 8;
	a = env->theme * a / env->zoom->iteration;
	if (x >= 0 && y >= 0 && x < FENE_X && y < FENE_Y)
	{
		ft_memcpy(&env->img->data[octet * x + env->img->sizeline * \
	y], &a, octet);
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
			"images/magnifique_black.xpm", w, h);
	env->church_img->img = mlx_xpm_file_to_image(env->mlx, \
			"images/church.xpm", w, h);
	env->sup_img->img = mlx_xpm_file_to_image(env->mlx, \
			"images/blancdim.XPM", w, h);
}
