/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:06:09 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/26 22:07:57 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_check_pause(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_P] && !holder->starting)
	{
		SDL_WarpMouseInWindow(WINDOW, WIDTH / 2, HEIGHT / 2);
		draw_text(holder, "Pause", WIDTH / 2, 10);
		SDL_RenderPresent(holder->renderer);
		holder->pause = (holder->pause == -1) ? 0 : 1;
		if (Mix_PausedMusic() == 0 && holder->pause)
			Mix_PauseMusic();
		else if (!holder->pause)
			Mix_ResumeMusic();
		if (SDL_GetRelativeMouseMode() == SDL_TRUE)
			SDL_SetRelativeMouseMode(SDL_FALSE);
		else
			SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	else if (holder->hud->lives <= 0)
	{
		draw_text(holder, "RETRY? y/n", WIDTH / 2, HEIGHT / 2 - 200);
		holder->retry_state = 1;
		SDL_RenderPresent(holder->renderer);
		holder->pause = (holder->pause == -1) ? 0 : 1;
	}
}

void		check_button(t_wolf *holder, t_camera *camera)
{
	if ((CHECK_L_X_2 == ';' || CHECK_L_X_2 == ':') && holder->keys.t)
	{
		if (CHECK_L_X_2 == ':')
		{
			CHECK_L_X_2 = ';';
			Mix_PlayChannel(-1, holder->camera->sound[6], 0);
		}
		else if (CHECK_L_X_2 == ';')
		{
			CHECK_L_X_2 = ':';
			Mix_PlayChannel(-1, holder->camera->sound[5], 0);
		}
		holder->keys.t = 0;
		holder->shadows = !holder->shadows;
	}
}

void		ft_check_weapons(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_1])
	{
		holder->gun = 0;
		holder->gun_1 = 0;
	}
	if (keystate[SDL_SCANCODE_2])
	{
		holder->gun = 1;
		holder->gun_1 = 1;
	}
	if (keystate[SDL_SCANCODE_3])
	{
		holder->gun = 2;
		holder->gun_1 = 0;
	}
	if (keystate[SDL_SCANCODE_4])
	{
		holder->gun = 3;
		holder->gun_1 = 0;
	}
}
