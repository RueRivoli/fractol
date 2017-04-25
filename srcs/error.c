/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:01:13 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/06 17:01:17 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_param_no_conform(void)
{
	ft_putstr("Le parametre n'est pas conforme\n");
}

void	error_no_file(void)
{
	ft_putstr("Le fichier n'existe pas\n");
}
