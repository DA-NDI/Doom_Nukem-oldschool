/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:04:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/23 21:06:55 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_check_pickups3(t_wolf *holder, int a)
{
	while (++a < holder->sprite_tex[6]->amount)
	{
		if (fabsf(holder->sprite[a + 19]->x - P_X) < 0.5 && \
			fabsf(holder->sprite[a + 19]->y - P_Y) < 0.5)
		{
			holder->hud->hp++;
			holder->sprite[a + 19]->is_alive = 0;
		}
	}
}

void	ft_check_pickups2(t_wolf *holder, int a)
{
	while (++a < holder->sprite_tex[4]->amount)
	{
		if (fabsf(holder->sprite[a + 13]->x - P_X) < 0.5 && \
			fabsf(holder->sprite[a + 13]->y - P_Y) < 0.5)
		{
			holder->hp++;
			holder->sprite[a + 13]->is_alive = 0;
		}
	}
	a = -1;
	while (++a < holder->sprite_tex[5]->amount)
	{
		if (fabsf(holder->sprite[a + 16]->x - P_X) < 0.5 && \
			fabsf(holder->sprite[a + 16]->y - P_Y) < 0.5)
		{
			holder->hud->hp++;
			holder->sprite[a + 16]->is_alive = 0;
		}
	}
	ft_check_pickups3(holder, -1);
}
