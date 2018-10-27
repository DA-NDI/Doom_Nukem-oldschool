/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:57:05 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/26 12:33:07 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

/*
**		hide mouse:
**		if (SDL_GetRelativeMouseMode() == SDL_TRUE)
**			SDL_SetRelativeMouseMode(SDL_FALSE);
**		else
**   SDL_SetRelativeMouseMode(SDL_TRUE);
*/

void		mouse_move(t_wolf *holder, t_camera *camera, float old)
{
	float old_plane_x;

	holder->keys.xrel = holder->event.motion.xrel;
	holder->keys.yrel = holder->event.motion.yrel;
	holder->updown -= holder->keys.yrel;
	holder->updown = (holder->updown < -350) ? -350 : holder->updown;
	holder->updown = (holder->updown > 650) ? 650 : holder->updown;
	old = DIR_X;
	DIR_X = DIR_X * cos(holder->keys.xrel / 100.0 * -0.3) \
		- DIR_Y * sin(holder->keys.xrel / 100.0 * -0.3);
	DIR_Y = old * sin(holder->keys.xrel / 100.0 * -0.3) \
		+ DIR_Y * cos(holder->keys.xrel / 100.0 * -0.3);
	old_plane_x = PLANE_X;
	PLANE_X = PLANE_X * cos(holder->keys.xrel / 100.0 * -0.3) \
		- PLANE_Y * sin(holder->keys.xrel / 100.0 * -0.3);
	PLANE_Y = old_plane_x * sin(holder->keys.xrel / 100.0 * -0.3) \
		+ PLANE_Y * cos(holder->keys.xrel / 100.0 * -0.3);
}

void		check_mousebuttons(t_wolf *holder)
{
	int		i;

	if (holder->event.type == SDL_MOUSEBUTTONDOWN)
	{
		if ((BUTTON_LEFT && !holder->starting && !holder->shooting) \
	&& ((AMMO > 0 && G != 1) || (holder->hud->rockets > 0 && G == 1)))
		{
			i = -1;
			holder->hud->ammo -= (G != 1) ? 1 : 0;
			holder->hud->rockets -= (G == 1) ? 1 : 0;
			while (++i < holder->sprite_tex[0]->amount)
				ft_check_click(holder, holder->sprite[i + 2]);
			holder->shooting = 1;
		}
	}
}

void		check_teleport(t_wolf *holder, t_camera *camera)
{
	holder->keys.enter = 0;
	if (holder->keys.up || holder->keys.w)
	{
		if (CHECK_UP_X == '2' && CHECK_UP_X_PLUS2 == '0')
		{
			P_X += DIR_X * MOV_SP + 2;
			Mix_PlayChannel(-1, camera->sound[0], 0);
		}
	}
	check_button(holder, camera);
}

void		ft_check_retry(t_wolf *holder, int key)
{
	if (key == SDLK_y && holder->retry_state)
	{
		holder->hud->lives = 3;
		holder->pause = 0;
		holder->frags = 0;
		holder->retry_state = 0;
		holder->hud->ammo = 25;
		holder->hud->rockets = 5;
		get_player_coordinates(holder, '0');
	}
	else if (key == SDLK_n && holder->retry_state)
	{
		draw_text(holder, "ASTALAVISTA, BABY!", WIDTH / 2, HEIGHT / 2 - 100);
		SDL_RenderPresent(holder->renderer);
		SDL_Delay(2000);
		ft_close(holder);
	}
}

void		ft_close_loop(t_wolf *holder, t_camera *camera)
{
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	check_teleport(holder, camera);
	azaporoz_action(holder, camera);
	azaporoz_rotate(holder, camera, 0);
	ft_check_advanced_move(holder, keystate);
	while (SDL_PollEvent(&(holder->event)))
	{
		if (holder->event.type == SDL_QUIT || C_Q)
			ft_close(holder);
		if (holder->event.type == SDL_MOUSEMOTION)
			mouse_move(holder, camera, 0);
		if (holder->event.type == SDL_KEYDOWN)
			azaporoz_keys_down(holder, camera, holder->event.key.keysym.sym);
		if (holder->event.type == SDL_KEYUP)
			azaporoz_keys_up(holder, camera, holder->event.key.keysym.sym);
		if (holder->event.type == SDL_KEYDOWN && holder->event.key.repeat == 0)
		{
			ft_check_retry(holder, holder->event.key.keysym.sym);
			ft_check_other(holder, keystate);
			ft_check_extra_keys(holder, keystate);
			ft_check_pause(holder, keystate);
		}
		check_mousebuttons(holder);
	}
}
