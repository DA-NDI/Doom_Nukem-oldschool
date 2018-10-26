/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:50:43 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/26 17:02:12 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	init_normal_mode(t_wolf *holder)
{
	holder->camera->move_speed = 0.08;
	holder->camera->rot_speed = -0.06;
	holder->hud->lives = 4;
	holder->hud->hp = 100;
	holder->hud->shield = 0;
	holder->hud->rockets = 30;
	holder->hud->ammo = 99;
	holder->hud->jetpack = 9000;
	holder->hud->level = 1;
	holder->hud->enemy_speed = 0.1;
}

void	init_insane_mode(t_wolf *holder)
{
	holder->camera->move_speed = 0.06;
	holder->camera->rot_speed = -0.06;
	holder->hud->lives = 1;
	holder->hud->hp = 1;
	holder->hud->shield = 0;
	holder->hud->rockets = 5;
	holder->hud->ammo = 25;
	holder->hud->jetpack = 1000;
	holder->hud->level = 1;
	holder->hud->enemy_speed = 0.5;
}

void	init_brutal_mode(t_wolf *holder)
{
	holder->camera->move_speed = 0.06;
	holder->camera->rot_speed = -0.06;
	holder->hud->lives = 1;
	holder->hud->hp = 1;
	holder->hud->shield = 0;
	holder->hud->rockets = 1;
	holder->hud->ammo = 5;
	holder->hud->jetpack = 10;
	holder->hud->level = 1;
	holder->hud->enemy_speed = 1;
}
