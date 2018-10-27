/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:04:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 14:31:33 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_check_pickups3(t_wolf *holder, int a)
{
	while (++a < holder->sprite_tex[6]->amount)
	{
		if (fabsf(holder->sprite[a + 19]->x - P_X) < 1 && \
			fabsf(holder->sprite[a + 19]->y - P_Y) < 1 && \
			holder->sprite[a + 19]->is_sprite)
		{
			holder->hud->hp += 10;
			holder->sprite[a + 19]->is_sprite = 0;
			Mix_PlayChannel(-1, holder->camera->sound[2], 0);
		}
	}
}

void	ft_check_pickups2(t_wolf *holder, int a)
{
	while (++a < holder->sprite_tex[4]->amount)
	{
		if (fabsf(holder->sprite[a + 13]->x - P_X) < 1 && \
			fabsf(holder->sprite[a + 13]->y - P_Y) < 1 && \
			holder->sprite[a + 13]->is_sprite)
		{
			holder->hp++;
			holder->sprite[a + 13]->is_sprite = 0;
			Mix_PlayChannel(-1, holder->camera->sound[2], 0);
		}
	}
	a = -1;
	while (++a < holder->sprite_tex[5]->amount)
	{
		if (fabsf(holder->sprite[a + 16]->x - P_X) < 1 && \
			fabsf(holder->sprite[a + 16]->y - P_Y) < 1 && \
			holder->sprite[a + 16]->is_sprite)
		{
			holder->hud->hp += 10;
			holder->sprite[a + 16]->is_sprite = 0;
			Mix_PlayChannel(-1, holder->camera->sound[2], 0);
		}
	}
	ft_check_pickups3(holder, -1);
	ft_check_bullet_collision(holder, -1);
}

void	ft_check_pickups(t_wolf *holder, int a)
{
	while (++a < holder->sprite_tex[2]->amount)
	{
		if (fabsf(CAR->x - P_X) < 1 && \
			fabsf(CAR->y - P_Y) < 1 && \
			CAR->is_sprite)
		{
			holder->energy += 10;
			CAR->is_sprite = 0;
			Mix_PlayChannel(-1, holder->camera->sound[8], 0);
		}
	}
	a = -1;
	while (++a < holder->sprite_tex[3]->amount)
	{
		if (fabsf(AMO->x - P_X) < 1 && \
			fabsf(AMO->y - P_Y) < 1 && \
			AMO->is_sprite)
		{
			holder->hud->ammo += 5;
			AMO->is_sprite = 0;
			Mix_PlayChannel(-1, holder->camera->sound[7], 0);
		}
	}
	ft_check_pickups2(holder, -1);
}
