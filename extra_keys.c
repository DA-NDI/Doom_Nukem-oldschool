/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:19:48 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/26 17:54:18 by avolgin          ###   ########.fr       */
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

void		ft_check_extra_keys(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_Q])
	{
		if (Mix_PausedMusic() == 0)
			Mix_PauseMusic();
		else
			Mix_ResumeMusic();
	}
	if (keystate[SDL_SCANCODE_RETURN] && holder->starting)
	{
		if (holder->start->play_select)
		{
			Mix_PlayMusic(holder->music, -1);
			holder->starting = 0;
		}
		else
		{
			// printf("close in return ! \n");
			ft_close(holder);
		}
	}
	if (keystate[SDL_SCANCODE_G])
		holder->shadows = !holder->shadows;
	ft_check_weapons(holder, keystate);
	ft_check_skybox(holder, keystate);
}

void		ft_check_click(t_wolf *holder, t_sprite *sprite)
{
	float		v_x;
	float		v_y;
	float 		angle;

//	if ((holder->event.button.button == SDL_BUTTON_LEFT && !holder->starting && !holder->shooting) \
//		&& ((holder->hud->ammo > 0 && G != 1) || (holder->hud->rockets > 0 && G == 1)))
//	{
		holder->hud->ammo -= (G != 1) ? 1 : 0;
		holder->hud->rockets -= (G == 1) ? 1 : 0;
		if (G == 1 || G == 0)
		{
			holder->sprite[1]->tex_sprite[0] = holder->sprite[1]->arr_sprite[G][0];
			holder->sprite[1]->is_alive = 1;
		}
printf("ONE\n");
//		holder->shooting = 1;
		Mix_PlayChannel(-1, holder->weapon[G]->pistol_shoot, 0);
		holder->weapon[G]->frame = 0;
		v_x = sprite->x - holder->player_x;
		v_y = sprite->y - holder->player_y;
		sprite->is_alive = (SHOOTS >= 4 || !IS_SPRITE) ? 0 : 1;
		IS_SPRITE = (SHOOTS >= 5 || !IS_ARC) ? 0 : 1;
		if (SHOOTS >= 5)
		{
			restart_enemy(holder, sprite);
			return;
		}
		angle = acos((v_x * holder->DIR_X + v_y * holder->DIR_Y) / (sqrt(v_x * v_x + v_y * v_y) * sqrt(holder->DIR_X * holder->DIR_X + holder->DIR_Y * holder->DIR_Y))) * 57.325;
		// printf("angle = %f\n", angle);
		if (angle < 5 && SHOOTS < 5 && IS_ARC)
		{
			SHOOTS += (G == 0) ? 1 : 2;
			SHOOTS += (G == 1) ? 2 : 0;
			// printf("HITTED! SHOOTS = %d H = %d\n", SHOOTS, H);
			if (SHOOTS < 5)
			{
				ARCADE_TEX = sprite->arr_sprite[H][SHOOTS];
			}

		}
//	}
}
