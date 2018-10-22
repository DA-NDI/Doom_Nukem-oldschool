/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:57:05 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 19:10:25 by avolgin          ###   ########.fr       */
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
}

void		ft_check_other(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_DOWN] && holder->starting)
	{
		SDL_RenderCopy(holder->renderer, START_SCR, NULL, NULL);
		draw_text(holder, "	  Play", WIDTH / 2 - 10, HEIGHT / 2);
		draw_text(holder, " > Quit", WIDTH / 2 - 10, HEIGHT / 2 + 15);
		draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
		holder->start->play_select = 0;
		SDL_RenderPresent(holder->renderer);
	}
	if (keystate[SDL_SCANCODE_UP] && holder->starting)
	{
		SDL_RenderCopy(holder->renderer, START_SCR, NULL, NULL);
		draw_text(holder, " > Play", WIDTH / 2 - 10, HEIGHT / 2);
		draw_text(holder, "	  Quit", WIDTH / 2 - 10, HEIGHT / 2 + 15);
		draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
		holder->start->play_select = 1;
		SDL_RenderPresent(holder->renderer);
	}
}


		// DIR_X += DIR_X * cos(holder->keys.xrel/ 100);
		// DIR_Y = DIR_Y * cos(holder->keys.xrel/ 100);
		// old_plane_x = PLANE_X;
		// PLANE_X = PLANE_X * cos(holder->keys.xrel/ 100);
		// PLANE_Y = PLANE_Y * cos(holder->keys.xrel/ 100);


void		mouse_move(t_wolf *holder, t_camera *camera, float old)
{
	float old_plane_x;

	holder->keys.xrel = holder->event.motion.xrel;
	holder->keys.yrel = holder->event.motion.yrel;
//	holder->keys.y = holder->event.motion.y;
//	holder->keys.x = holder->event.motion.x;
	// holder->updown = HEIGHT / 2 - holder->event.motion.y + holder->start_point;
	holder->updown -= holder->keys.yrel;// + holder->start_point;
	holder->updown = (holder->updown < -350) ? -350 : holder->updown;

		// old = DIR_X;
		// DIR_X = DIR_X * cos(holder->keys.xrel * 2.0 / 100.0 * -1.0) - DIR_Y * sin(holder->keys.xrel * 2.0 / 100.0 * -1.0);
		// DIR_Y = old * sin(holder->keys.xrel * 2.0 / 100.0 * -1.0) + DIR_Y * cos(holder->keys.xrel * 2.0 / 100.0 * -1.0);
		// old_plane_x = PLANE_X;
		// PLANE_X = PLANE_X * cos(holder->keys.xrel * 2.0 / 100.0 * -1.0) - PLANE_Y * sin(holder->keys.xrel * 2.0 / 100.0 * -1.0);
		// PLANE_Y = old_plane_x * sin(holder->keys.xrel * 2.0 / 100.0 * -1.0) + PLANE_Y * cos(holder->keys.xrel * 2.0 / 100.0 * -1.0);
		old = DIR_X;
		DIR_X = DIR_X * cos(holder->keys.xrel / 100.0 * -0.3) - DIR_Y * sin(holder->keys.xrel / 100.0 * -0.3);
		DIR_Y = old * sin(holder->keys.xrel / 100.0 * -0.3) + DIR_Y * cos(holder->keys.xrel / 100.0 * -0.3);
		old_plane_x = PLANE_X;
		PLANE_X = PLANE_X * cos(holder->keys.xrel / 100.0 * -0.3) - PLANE_Y * sin(holder->keys.xrel / 100.0 * -0.3);
		PLANE_Y = old_plane_x * sin(holder->keys.xrel / 100.0 * -0.3) + PLANE_Y * cos(holder->keys.xrel / 100.0 * -0.3);
}

void		check_teleport(t_wolf *holder, t_camera *camera)
{
	if (CHECK_UP_X_PLUS2 == ':' && holder->keys.enter)
	{
		holder->shadows = 0;
		CHECK_UP_X_PLUS2 = ';';
		printf("CLICK!\n");
	}
	else if (CHECK_UP_X_PLUS2 == ';' && holder->keys.enter)
	{
		holder->shadows = 1;
		CHECK_UP_X_PLUS2 = ':';
	}
	else if (CHECK_UP_X_MINUS2 == ':' && holder->keys.enter)
	{
		holder->shadows = 0;
		CHECK_UP_X_MINUS2 = ';';
	}
	else if (CHECK_UP_X_MINUS2 == ';' && holder->keys.enter)
	{
		holder->shadows = 1;
		CHECK_UP_X_MINUS2 = ':';		
	}
	holder->keys.enter = 0;
	if (holder->keys.up || holder->keys.w)
	{
		if (CHECK_UP_X == '2' && CHECK_UP_X_PLUS2 == '0')
		{
			P_X += DIR_X * MOV_SP + 2;
			Mix_PlayChannel(-1, camera->dstelept, 0);
		}
	}

}

void		ft_close_loop(t_wolf *holder, t_camera *camera)
{
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	check_teleport(holder, camera);
	azaporoz_action(holder, camera);
	azaporoz_rotate(holder, camera, 0);

//	holder->updown = (holder->updown < 1000 || holder->updown < -1000) ? HEIGHT / 2 - holder->event.motion.y + holder->start_point - holder->height_map[(int)P_Y][(int)P_X] : 0;

	ft_check_advanced_move(holder, keystate);
	while (SDL_PollEvent(&holder->event))
	{
		if (holder->event.type == SDL_QUIT || C_Q)
		{
			printf("CLOSE in polevent\n");
			ft_close(holder);
		}
		if (holder->event.type == SDL_MOUSEMOTION)
			mouse_move(holder, camera, 0);
		if (holder->event.type == SDL_KEYDOWN)
			azaporoz_keys_down(holder, camera, holder->event.key.keysym.sym);
		if (holder->event.type == SDL_KEYUP)
			azaporoz_keys_up(holder, camera, holder->event.key.keysym.sym);
		if (holder->event.type == SDL_KEYDOWN && holder->event.key.repeat == 0)
		{
			ft_check_other(holder, keystate);
			ft_check_extra_keys(holder, keystate);
			ft_check_pause(holder, keystate);
		}
		if (holder->event.type == SDL_MOUSEBUTTONDOWN)
			ft_check_click(holder, holder->sprite[0]);
	}
}
