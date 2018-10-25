/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:29:37 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/23 14:29:38 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

unsigned int	get_pixel(SDL_Surface *surface, int x, int y)
{
	unsigned int	*pixels;

	y = (y < 0 || y > 767) ? 0 : y;
	x = (x < 0 || x > 1023 || (x == 0 && y == 0)) ? 1 : x;
	pixels = (unsigned int*)surface->pixels;
	return (pixels[(y * surface->w) + x]);
}
