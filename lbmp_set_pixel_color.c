/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_set_pixel_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 22:38:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/02 06:40:03 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

/*
**I can use memcpy!
*/

int	lbmp_set_pixel_color(t_lbmp *lbmp, int x, int y, uint32_t color)
{
	int				i;
	unsigned char	*pixel_ptr;
	unsigned char	*color_ptr;

	if (lbmp == NULL)
		return (-1);
	pixel_ptr = (unsigned char *)lbmp_int_get_pixel_ptr(lbmp, x, y);
	color_ptr = (unsigned char *)&color;
	i = (lbmp->iheader.bpp / 8);
	while (i--)
		*pixel_ptr++ = *color_ptr++;
	return (0);
}
