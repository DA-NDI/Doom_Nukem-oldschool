/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor1_fixed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:18:33 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/18 17:18:34 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			draw_floor1(t_wolf *holder, \
unsigned int buffer[][holder->width], unsigned int x, int_fix f_dist_player)
{
	int		i;
	int_fix f_current_dist;
	int_fix f_weight;
	int_fix f_current_floor_x;
	int_fix f_current_floor_y;

	i = holder->camera->draw_end;
	f_dist_player = 0.0;
	while (++i < holder->height)
	{
		f_current_dist = (FIX_DIV(INT_F(holder->height), INT_F((i << 1)\
					- holder->height)));
		f_weight = FIX_DIV(f_current_dist - f_dist_player, \
					(FLOAT_F(PERP_DIST_WALL) - f_dist_player));
		f_current_floor_x = FIX_MULT(f_weight, FLOAT_F(WALL_X_FL)) \
					+ FIX_MULT(256 - f_weight, FLOAT_F(P_X));
		f_current_floor_y = FIX_MULT(f_weight, FLOAT_F(WALL_Y_FL)) + \
					FIX_MULT(256 - f_weight, FLOAT_F(P_Y));
		buffer[i][x] = get_pixel(holder->camera->texture[4], \
		((int)(FIXED_F(f_current_floor_x) * 64) % 64) >> 1, \
		(int)(FIXED_F(f_current_floor_y) * 64) % 64);
	}
}
