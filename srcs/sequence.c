/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:26:23 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/05 19:17:37 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sequence_mandelbrot(t_node *node, float re_cte, float im_cte)
{
	float		mem;

	mem = node->re_z;
	node->re_z = node->re_z * node->re_z - node->im_z * node->im_z + re_cte;
	node->im_z = 2 * node->im_z * mem + im_cte;
}

void		sequence_bship(t_node *node, float re_cte, float im_cte)
{
	float		mem;

	mem = node->re_z;
	node->re_z = fabsf(node->re_z * node->re_z) - \
				fabsf(node->im_z * node->im_z) + re_cte;
	node->im_z = 2 * fabsf(node->im_z * mem) + im_cte;
}

void		sequence_julia(t_node *node, float re_cte, float im_cte)
{
	float		mem;

	mem = node->re_z;
	node->re_z = node->re_z * node->re_z - node->im_z * node->im_z + re_cte;
	node->im_z = 2 * node->im_z * mem + im_cte;
}

void		sequence_myfractal(t_node *node, float re_cte, float im_cte)
{
	float		mem;

	mem = node->re_z;
	node->re_z = fabs(node->re_z * node->re_z - \
			node->im_z * node->im_z) + re_cte;
	node->im_z = -2 * node->im_z *
		mem + im_cte;
}
