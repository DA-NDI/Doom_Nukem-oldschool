/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_azaporoz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:49:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 21:38:11 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	azaporoz_keys_down(t_wolf *holder, t_camera *camera, int key)
{
	azaporoz_keys_down_2(holder, camera, key);
	if (key == SDLK_LCTRL && holder->advanced == normal)
	{
		holder->keys.lctrl = 1;
		holder->advanced = crouch;
	}
	if (key == SDLK_f && holder->advanced == normal && holder->updown >= 0)
	{
		holder->advanced = flying;
		holder->start_point = holder->updown;
		holder->keys.f = 1;
	}
	if (key == SDLK_SPACE && holder->advanced == normal)
		holder->advanced = jumping;
	if (key == SDLK_RETURN)
		holder->keys.t = 1;
}

void	azaporoz_keys_up(t_wolf *holder, t_camera *camera, int key)
{
	azaporoz_keys_up_2(holder, camera, key);
	if (key == SDLK_RETURN)
		holder->keys.t = 0;
	if (key == SDLK_f)
	{
		holder->keys.f = 0;
		holder->start_point = 0;
		holder->lifted = 0;
	}
}

void	azaporoz_left_right(t_wolf *holder, t_camera *camera)
{
	CHECK_UP_X = (CHECK_UP_X == '3' && holder->keys.z) ? '0' : CHECK_UP_X;
	if (CHECK_UP_Y == '3' && holder->keys.z)
		CHECK_UP_Y = '0';
	if (holder->keys.left || holder->keys.a)
	{
		if (CHECK_LEFT_X == '0' || CHECK_LEFT_X == 'P')
			P_X -= (DIR_Y) * MOV_SP;
		if (CHECK_LEFT_Y == '0' || CHECK_LEFT_Y == 'P')
			P_Y += (DIR_X) * MOV_SP;
	}
	if (holder->keys.right || holder->keys.d)
	{
		if (CHECK_RIGHT_X == '0' || CHECK_RIGHT_X == 'P')
			P_X += (DIR_Y) * MOV_SP;
		if (CHECK_RIGHT_Y == '0' || CHECK_RIGHT_Y == 'P')
			P_Y -= (DIR_X) * MOV_SP;
	}
}

void	azaporoz_action(t_wolf *holder, t_camera *camera)
{
	if (holder->keys.up || holder->keys.w)
	{
		if (CHECK_UP_X == '0' || CHECK_UP_X == 'P')
			P_X += DIR_X * MOV_SP;
		if (CHECK_UP_Y == '0' || CHECK_UP_Y == 'P')
			P_Y += DIR_Y * MOV_SP;
	}
	if (holder->keys.down || holder->keys.s)
	{
		if (CHECK_DOWN_X == '0' || CHECK_DOWN_X == 'P')
			P_X -= DIR_X * MOV_SP;
		if (CHECK_DOWN_Y == '0' || CHECK_DOWN_Y == 'P')
			P_Y -= DIR_Y * MOV_SP;
	}
	azaporoz_left_right(holder, camera);
}

void	azaporoz_rotate(t_wolf *holder, t_camera *camera, float old)
{
	float old_plane_x;

	if (holder->keys.right)
	{
		old = DIR_X;
		DIR_X = DIR_X * cos(ROT_SPEED) - DIR_Y * sin(ROT_SPEED);
		DIR_Y = old * sin(ROT_SPEED) + DIR_Y * cos(ROT_SPEED);
		old_plane_x = PLANE_X;
		PLANE_X = PLANE_X * cos(ROT_SPEED) - camera->plane_y * sin(ROT_SPEED);
		PLANE_Y = old_plane_x * sin(ROT_SPEED) + PLANE_Y * cos(ROT_SPEED);
	}
	if (holder->keys.left)
	{
		old = DIR_X;
		DIR_X = DIR_X * cos(-ROT_SPEED) - DIR_Y * sin(-ROT_SPEED);
		DIR_Y = old * sin(-ROT_SPEED) + DIR_Y * cos(-ROT_SPEED);
		old_plane_x = PLANE_X;
		PLANE_X = PLANE_X * cos(-ROT_SPEED) - camera->plane_y * sin(-ROT_SPEED);
		PLANE_Y = old_plane_x * sin(-ROT_SPEED) + PLANE_Y * cos(-ROT_SPEED);
	}
}
