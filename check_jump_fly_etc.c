/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_jump_fly_etc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:08:50 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 21:32:02 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_check_jump(t_wolf *holder, const Uint8 *keystate)
{
	if (holder->advanced == jumping)
	{
		holder->adv_frames++;
		if (holder->adv_frames < 20)
			holder->extra_updown += 2;
		else if (holder->adv_frames >= 20)
			holder->extra_updown -= 2;
		if (holder->adv_frames == 40)
		{
			holder->adv_frames = 0;
			holder->advanced = normal;
			holder->extra_updown = 0;
		}
		printf ("i'm jumping, holder->extra_updown == %d\n", holder->extra_updown);
	}
//		holder->jumping = 1;
}

void	ft_check_fly(t_wolf *holder, const Uint8 *keystate)
{
	if (holder->advanced == flying && holder->keys.f == 1 && holder->hud->jetpack > 0)
	{
		holder->lifted++;
		holder->hud->jetpack--;
		holder->extra_updown = holder->lifted;
		printf ("i'm flying holder->lifted = %d updown = %d	\
holder->start_point = %d, holder->extra_updown == %d\n", holder->lifted, holder->updown, holder->start_point, holder->extra_updown);
	}
	if (holder->advanced == flying && holder->keys.f == 0)
	{
		if ((holder->extra_updown - holder->start_point) > 0)
			holder->extra_updown--;
		else if ((holder->extra_updown - holder->start_point) < 0)
			holder->extra_updown++;
		if (holder->extra_updown == 0)
			holder->advanced = normal;
	}
	if (abs(holder->extra_updown) > 1000)
		holder->extra_updown = 0;
}
void	ft_check_sit(t_wolf *holder, const Uint8 *keystate)
{
	if (holder->advanced == crouch)
	{
		if (holder->keys.lctrl == 1 && holder->adv_frames < 15)
		{
			holder->adv_frames++;
			holder->extra_updown -= 4;
		}
		if (holder->keys.lctrl == 0)
		{
			if (holder->adv_frames-- > 0)
				holder->extra_updown += 4;
			if (holder->adv_frames == 0)
			{
				holder->advanced = normal;
				holder->extra_updown = 0;
			}
		}
		printf("i'm crouching, holder->extra_updown == %d\n", holder->extra_updown);

	}
}
void	ft_check_getup(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_LCTRL])
	{
		holder->keys.y -= 100;
	}
}
void	ft_check_advanced_move(t_wolf *holder, const Uint8 *keystate)
{

	ft_check_jump(holder, keystate);
	ft_check_fly(holder, keystate);
	ft_check_sit(holder, keystate);
	ft_check_getup(holder, keystate);
}
