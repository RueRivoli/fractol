/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:52:14 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/10 16:51:59 by fgallois         ###   ########.fr       */
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

void		zoom(t_env *env, int x, int y);
void		dezoom(t_env *env, int x, int y);
void	    refresh(t_env *env);
void	    translation(t_env *env, int i);
void	    restart(t_env *env);

/*
** error.c
*/

void	    error_param_no_conform(void);
void	    error_no_file(void);


/*
** event_function.c
*/


int			key_funct(int keycode, t_env *env);

int			mouse_funct(int button, int x, int y, t_env *env);

void		key_funct_2(int keycode, t_env *env);

int			key_funct(int keycode, t_env *env);


/*
** inter.c
*/

float		value_x(t_env *env, int x);
float		value_y(t_env *env, int y);
int			get_color(char *str);
void	    trace(t_env *env);
void	modify_coord(t_env *env);

/*
** ft_itohex.c
*/

char			*ft_intermediate(int i, char *str, int fact, int k);

char			*ft_itohex(int i);

/*
** init_env.c
*/

void		new_one(t_env *env);

//void		new_two(t_env *env);

void        new_mandelbrot(t_env *env);

void        new_julia(t_env *env);

void		adapt_to_fractal(t_env *env);

t_env		*new_env(void);

void        new_zoom(t_env *env);

t_env		*init_env(char *av1);

/*
** init_img.c
*/

void		mlx_put_pixel_to_imagec(t_env *env, int x, int y, char *str);

void		mlx_put_pixel_to_imagei(t_env *env, int x, int y, int a);

t_img		*init_img(t_env *env, int height, int width);

void		fill_img(t_env *env, int *h, int *w);

char        *rgb_to_pchar(t_env *env, int rn, int gn, int bn);

/*
** main.c
*/

char		*get_file_name(char *av1);

t_env		*handle_error(int argc, char **argv);

void		ft_hook(t_env *env);

/*
** print.c
*/

void		print_all(t_env *env);
void		print_image_graph(t_env *env);
void		print_image_supp(t_env *env);
void		print_image_back(t_env *env);


/*
** trace.c
*/


void        initialise_coef(t_env *env);
void	    check_extremes(t_env *env, int x, int y);
void		change_coef_zoom(t_env *env, int x, int y);
void		change_coef_dezoom(t_env *env, int x, int y);
void		trace_mandelbrot(t_env *env);
void		trace_julia(t_env *env);
char	    *ft_tohex(int h, float s, float l);

#endif
