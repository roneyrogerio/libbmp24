/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_int_get_pixel_ptr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 02:05:22 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/02 06:44:06 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

void	*lbmp_int_get_pixel_ptr(t_lbmp *lbmp, int x, int y)
{
	int	offset;
	int	stride;
	int width;
	int height;

	if (lbmp == NULL || lbmp->data == NULL)
		return (NULL);
	height = lbmp->iheader.height;
	width = lbmp->iheader.width;
	stride = ((((width * lbmp->iheader.bpp) + 31) & ~31) >> 3);
	offset = ((height - y - 1) * stride + x * (lbmp->iheader.bpp / 8));
	return (lbmp->data + offset);
}
