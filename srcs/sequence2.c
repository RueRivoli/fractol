/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:17:59 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/05 19:20:20 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sequence_chameleon(t_node *node, float re_cte, float im_cte)
{
	float		mem;

	mem = node->re_z;
	node->re_z = node->re_z * node->re_z - node->im_z * node->im_z + re_cte;
	node->im_z = -2 * node->im_z * mem + im_cte;
}

void		sequence_sword(t_node *node, float re_cte, float im_cte)
{
	float		mem;

	mem = node->re_z;
	node->re_z = fabs(node->re_z * node->re_z - \
			node->im_z * node->im_z + re_cte);
	node->im_z = fabs(2 * node->im_z *
			mem + im_cte);
}

void		sequence_celtic(t_node *node, float re_cte, float im_cte)
{
	float		mem;

	mem = node->re_z;
	node->re_z = fabs(node->re_z * node->re_z - \
			node->im_z * node->im_z) + re_cte;
	node->im_z = 2 * node->im_z *
		mem + im_cte;
}

void		sequence_tricorn(t_node *node, float re_cte, float im_cte)
{
	float		mem;

	mem = node->re_z;
	node->re_z = node->re_z * node->re_z - node->im_z * node->im_z + re_cte;
	node->im_z = -2 * node->im_z * mem + im_cte;
}
