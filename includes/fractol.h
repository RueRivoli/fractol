/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:52:14 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 20:34:15 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "define.h"
# include "struct.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

/*
 ** change_view.c
 */

void		refresh(t_env *env);
void		moovable(t_env *env);
void		change_iteration(t_env *env, int sign);
void		change_color(t_env *env, int color);

/*
 ** change_view2.c
 */

void		translation(t_env *env, int i);
void		restart(t_env *env);
float		power(int nb_zoom, float num);
void		zoom(t_env *env, int x, int y);
void		dezoom(t_env *env, int x, int y);

/*
 ** error.c
 */

void		error_param_no_conform(void);
void		error_no_file(void);
void		error_no_image(void);

/*
 ** event_function.c
 */

void		key_funct2(int keycode, t_env *env);
int			key_funct(int keycode, t_env *env);
int			mouse_funct(int button, int x, int y, t_env *env);
int			mouse_funct_moovable(int x, int y, t_env *env);

/*
 ** init_env.c
 */

void		new_one(t_env *env);
t_env		*new_env(void);
void		name2(t_env *env, char *av1);
void		name(t_env *env, char *av1);
t_env		*init_env(char *av1);

/*
 ** init_img.c
 */

void		mlx_put_pixel_to_image(t_env *env, int x, int y, int color);
t_img		*init_img(t_env *env, int height, int width);
int			fill_img(t_env *env, int *h, int *w);

/*
 ** initial_value.c
 */
void		new_mandelbrot(t_env *env);
void		new_bship(t_env *env);
void		new_julia(t_env *env);
void		new_zoom(t_env *env);
void		adapt_to_fractal(t_env *env);

/*
 ** inter.c
 */

float		value_x(t_env *env, int x);
float		value_y(t_env *env, int y);
t_node		*init_node();
void		modify_coord(t_env *env);


/*
 ** main.c
 */

t_env		*handle_error(int argc, char **argv);
void		ft_hook(t_env *env);

/*
 ** print.c
 */

void		print_image_back(t_env *env);
void		print_image_supp(t_env *env);
void		print_image_graph(t_env *env);
void		print_image_sign(t_env *env);
void		print_all(t_env *env);

/*
 ** printandseq.c
 */

int			print_menu(t_env *env);
int			print_title(t_env *env);
void		apply_sequence_jul(t_env *env, t_node *node, float re_cte, float im_cte);
void		apply_sequence_man(t_env *env, t_node *node, float re_cte, float im_cte);

/*
 ** sequence.c
 */

void		sequence_mandelbrot(t_node *node, float re_cte, float im_cte);
void		sequence_bship(t_node *node, float re_cte, float im_cte);
void		sequence_julia(t_node *node, float re_cte, float im_cte);
void        sequence_myfractal(t_node *node, float re_cte, float im_cte);

/*
 ** sequence2.c
 */

void        sequence_chameleon(t_node *node, float re_cte, float im_cte);
void        sequence_sword(t_node *node, float re_cte, float im_cte);
void        sequence_celtic(t_node *node, float re_cte, float im_cte);
void        sequence_tricorn(t_node *node, float re_cte, float im_cte);


/*
 ** trace.c
 */

void		convergence_mandelbrot(t_env *env, t_node *node, int x, int y);
void		trace_mandelbrot(t_env *env);
void		convergence_julia(t_env *env, t_node *node, int x, int y);
void		trace_julia(t_env *env);
void		trace(t_env *env);


#endif
