/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:45:03 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/01 18:31:53 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H


typedef struct	s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_img;


typedef struct	s_node
{
	float	re_z;
	float 	im_z;
}				t_node;


typedef struct 	s_man
{
	float 	alphax;
	float 	alphay;
	float 	x_0;
	float 	y_0;
	int		cte_x;
	int		cte_y;

}				t_man;


typedef struct 	s_jul
{
	float 	re_cte;
	float	im_cte;

	float 	alphax;
	float 	alphay;

	float 	x_0;
	float 	y_0;
	int		cte_x;
	int		cte_y;

}				t_jul;

typedef struct s_zoom
{
	float 	zoom;
	int 	nb_zoom;
	int		x_zoom;
	int		y_zoom;

	int		x_translation;
	int		y_translation;
	int		prec_zoom;
	int		prec_dezoom;
	int 	iteration;
}				t_zoom;


typedef struct	s_env
{
	void	*mlx;
	void	*win;
	
	t_img	*img;
	t_img	*back_img;
	t_img	*sup_img;
	t_img	*church_img;

	int number;
	char *fractal_name;

	t_node	**map;
	t_zoom	*zoom;

	float 	x_init;
	float 	x_fin;
	float 	y_init;
	float 	y_fin;

	t_jul*	jul;
	t_man*	man;

	int moovable;
	int theme;
}				t_env;

#endif
