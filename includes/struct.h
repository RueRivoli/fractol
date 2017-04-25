/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:45:03 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/10 19:52:10 by fgallois         ###   ########.fr       */
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
	int		x;
	int		y;
	int		color_num;
}				t_node;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	
	t_img	*img;
	t_img	*back_img;
	t_img	*sup_img;
	t_img	*church_img;


	t_node	**map;

	int		x;
	int		y;

	float 	zoom;
	int		x_zoom;
	int		y_zoom;
	int		x_pre_zoom;
	int		y_pre_zoom;
	float 	alphax;
	float 	alphay;

	float 	x_0;
	float 	y_0;
	float 	x_init;
	float 	x_fin;
	float 	y_init;
	float 	y_fin;
	int		x_translation;
	int		y_translation;
	int		prec_zoom;
	int		prec_dezoom;
	int 	iteration;
	int		cte_x;
	int		cte_y;
	int		bool_color;
	char	*fractal_name;
}				t_env;

#endif
