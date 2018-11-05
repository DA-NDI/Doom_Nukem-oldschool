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

void	ft_check_jump(t_wolf *holder)
{
	if (holder->advanced == jumping)
	{
		holder->adv_frames++;
		if (holder->adv_frames < 15)
			holder->extra_updown += 8;
		else if (holder->adv_frames >= 15)
			holder->extra_updown -= 8;
		if (holder->adv_frames == 30)
		{
			Mix_PlayChannel(-1, holder->camera->sound[3], 0);
			holder->adv_frames = 0;
			holder->advanced = normal;
			holder->extra_updown = 0;
		}
	}
}

void	ft_check_fly(t_wolf *holder)
{
	if (holder->advanced == flying && holder->keys.f ==\
	1 && holder->hud->jetpack > 0)
	{
		holder->lifted += 5;
		holder->hud->jetpack--;
		holder->extra_updown = holder->lifted;
	}
	if (holder->advanced == flying && holder->keys.f == 0)
	{
		if ((holder->extra_updown - holder->start_point) > 0)
			holder->extra_updown -= 5;
		else if ((holder->extra_updown - holder->start_point) < 0)
			holder->extra_updown++;
		if (holder->extra_updown == 0)
			holder->advanced = normal;
	}
	if (abs(holder->extra_updown) > 1000)
		holder->extra_updown = 0;
}

void	ft_check_sit(t_wolf *holder)
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
	ft_check_jump(holder);
	ft_check_fly(holder);
	ft_check_sit(holder);
	ft_check_getup(holder, keystate);
}
