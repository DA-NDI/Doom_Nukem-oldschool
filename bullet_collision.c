/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:57:35 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/24 19:06:15 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#define B holder->sprite[0]
#define B holder->sprite[0]

void	ft_check_bull_2(t_wolf *holder, int a)
{
	while (++a < holder->sprite_tex[6]->amount)
	{
		if (fabsf(holder->sprite[a + 19]->x - B->x) < 0.3 && \
			fabsf(holder->sprite[a + 19]->y - B->y) < 0.3 && \
			holder->sprite[a + 19]->is_sprite)
		{
			B->is_sprite = 0;
			B->is_alive = 0;
		}
	}
}

void	ft_check_bull_1(t_wolf *holder, int a)
{
	while (++a < holder->sprite_tex[2]->amount)
	{
		if (fabsf(holder->sprite[a + 7]->x - B->x) < 0.3 && \
			fabsf(holder->sprite[a + 7]->y - B->y) < 0.3 && \
			holder->sprite[a + 7]->is_sprite)
		{
			B->is_sprite = 0;
			B->is_alive = 0;
		}
	}
	a = -1;
	while (++a < holder->sprite_tex[3]->amount)
	{
		if (fabsf(holder->sprite[a + 10]->x - B->x) < 0.3 && \
			fabsf(holder->sprite[a + 10]->y - B->y) < 0.3 && \
			holder->sprite[a + 10]->is_sprite)
		{
			B->is_sprite = 0;
			B->is_alive = 0;
		}
	}
}

void	ft_check_bullet_collision(t_wolf *holder, int a)
{
	while (++a < holder->sprite_tex[4]->amount)
	{
		if (fabsf(holder->sprite[a + 13]->x - B->x) < 0.3 && \
			fabsf(holder->sprite[a + 13]->y - B->y) < 0.3 && \
			holder->sprite[a + 13]->is_sprite)
		{
			B->is_sprite = 0;
			B->is_alive = 0;
		}
	}
	a = -1;
	while (++a < holder->sprite_tex[5]->amount)
	{
		if (fabsf(holder->sprite[a + 16]->x - B->x) < 0.3 && \
			fabsf(holder->sprite[a + 16]->y - B->y) < 0.3 && \
			holder->sprite[a + 16]->is_sprite)
		{
			B->is_sprite = 0;
			B->is_alive = 0;
		}
	}
	ft_check_bull_1(holder, -1);
	ft_check_bull_2(holder, -1);
}
