/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:01:13 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/04 20:24:43 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_param_no_conform(void)
{
	ft_putstr("Le parametre n'est pas compatible\n");
}

void	error_no_file(void)
{
	ft_putstr("Le fichier n'existe pas\n");
}

void	error_no_image(void)
{
	ft_putstr("Il semblerait que les images soient mal stockees\n");
	ft_putstr("Compilez dans le dossier parent. Merci\n");
}
