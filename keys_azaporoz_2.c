/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_azaporoz_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:46:18 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/27 21:37:42 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	azaporoz_keys_down_2(t_wolf *holder, t_camera *camera, int key)
{
	if (key == SDLK_RIGHT)
		holder->keys.right = 1;
	if (key == SDLK_LEFT)
		holder->keys.left = 1;
	if (key == SDLK_UP)
		holder->keys.up = 1;
	if (key == SDLK_DOWN)
		holder->keys.down = 1;
	if (key == SDLK_w)
		holder->keys.w = 1;
	if (key == SDLK_s)
		holder->keys.s = 1;
	if (key == SDLK_a)
		holder->keys.a = 1;
	if (key == SDLK_d)
		holder->keys.d = 1;
	if (key == SDLK_LSHIFT && holder->energy)
	{
		holder->energy--;
		MOV_SP = 0.18;
	}
	if (key == SDLK_z)
		holder->keys.z = 1;
}

void	azaporoz_keys_up_3(t_wolf *holder, int key)
{
	if (key == SDLK_o && holder->hud->hp <= 150 && holder->hp)
	{
		holder->hud->hp += 10;
		holder->hp--;
	}
	if (key == SDLK_o && holder->hud->hp <= 150 && holder->hp)
	{
		holder->hud->hp += 10;
		holder->hp--;
	}
	if (key == SDLK_z)
		holder->keys.z = 1;
}

void	azaporoz_keys_up_2(t_wolf *holder, t_camera *camera, int key)
{
	if (key == SDLK_RIGHT)
		holder->keys.right = 0;
	if (key == SDLK_LEFT)
		holder->keys.left = 0;
	if (key == SDLK_UP)
		holder->keys.up = 0;
	if (key == SDLK_DOWN)
		holder->keys.down = 0;
	if (key == SDLK_w)
		holder->keys.w = 0;
	if (key == SDLK_s)
		holder->keys.s = 0;
	if (key == SDLK_a)
		holder->keys.a = 0;
	if (key == SDLK_d)
		holder->keys.d = 0;
	if (key == SDLK_LSHIFT)
		MOV_SP = 0.07;
	if (key == SDLK_LCTRL)
		holder->keys.lctrl = 0;
	azaporoz_keys_up_3(holder, key);
}
