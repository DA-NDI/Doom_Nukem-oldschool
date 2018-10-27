/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:19:48 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/26 22:09:23 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_check_skybox(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_W])
		holder->skybox_num = 0;
	if (keystate[SDL_SCANCODE_E])
		holder->skybox_num = 2;
	if (keystate[SDL_SCANCODE_R])
		holder->skybox_num = 3;
}

void		ft_check_enter_start(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_RETURN] && holder->starting)
	{
		if (holder->start->play_select && holder->starting == 1)
		{
			holder->starting = 2;
			holder->start->play_select = 2;
			ft_draw_menu_2(holder);
		}
		else if (holder->start->play_select && holder->starting == 2)
		{
			init_mode(holder, holder->start->play_select);
			Mix_PlayMusic(holder->music, -1);
			holder->starting = 0;
		}
		else
			ft_close(holder);
	}
}

void		ft_check_extra_keys(t_wolf *holder, const Uint8 *keystate)
{
	ft_check_enter_start(holder, keystate);
	if (keystate[SDL_SCANCODE_Q])
	{
		if (Mix_PausedMusic() == 0)
			Mix_PauseMusic();
		else
			Mix_ResumeMusic();
	}
	if (keystate[SDL_SCANCODE_G])
		holder->shadows = !holder->shadows;
	if (keystate[SDL_SCANCODE_T])
		holder->tv_mode = !holder->tv_mode;
	if (keystate[SDL_SCANCODE_I] || holder->hud->level == 4)
		holder->transparent = !holder->transparent;
	ft_check_weapons(holder, keystate);
	ft_check_skybox(holder, keystate);
}

void		ft_gun_fire_on(t_wolf *holder)
{
	if (G == 1 || G == 0)
	{
		holder->sprite[0]->tex_sprite[0] = \
		holder->sprite[0]->s_tex->arr_sprite[G][0];
		holder->sprite[0]->is_alive = 1;
		holder->sprite[0]->is_sprite = 1;
	}
}

/*
** 57.325 is magic number (180 / PI) for angle to multiply
*/

void		ft_check_click(t_wolf *holder, t_sprite *sprite)
{
	float		v_x;
	float		v_y;
	float		angle;

	ft_gun_fire_on(holder);
	Mix_PlayChannel(-1, holder->weapon[G]->pistol_shoot, 0);
	holder->weapon[G]->frame = 0;
	v_x = sprite->x - holder->player_x;
	v_y = sprite->y - holder->player_y;
	sprite->is_alive = (SHOOTS >= 4 || !IS_SPRITE) ? 0 : 1;
	IS_SPRITE = (SHOOTS > 5 || !IS_ARC) ? 0 : 1;
	angle = acos((v_x * holder->DIR_X + v_y * holder->DIR_Y) / (sqrt(v_x * v_x \
	+ v_y * v_y) * sqrt(pow(holder->DIR_X, 2) + pow(holder->DIR_Y, 2))));
	if (angle < 0.0872 && SHOOTS <= 5 && IS_ARC)
	{
		SHOOTS += (G == 0) ? 1 : 2;
		SHOOTS += (G == 1) ? 2 : 0;
		if (SHOOTS < 5)
			sprite->tex_sprite[0] = sprite->s_tex->arr_sprite[H][SHOOTS];
	}
	if (SHOOTS > 5)
	{
		restart_enemy(holder, sprite);
		return ;
	}
}
