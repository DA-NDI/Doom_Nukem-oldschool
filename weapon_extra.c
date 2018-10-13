/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 06:05:14 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/20 06:47:18 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	init_shotgun_tex(t_weapon *weapon, t_wolf *holder)
{
	weapon->texture_sshotgun[4] = load_tex(RENDER, "./textures/SSGRC0.png");
	weapon->texture_sshotgun[5] = load_tex(RENDER, "./textures/SSGRD0.png");
	weapon->texture_sshotgun[6] = load_tex(RENDER, "./textures/SSGRE0.png");
	weapon->texture_sshotgun[7] = load_tex(RENDER, "./textures/SSGRF0.png");
	weapon->texture_sshotgun[8] = load_tex(RENDER, "./textures/SSGRG0.png");
	weapon->texture_sshotgun[9] = load_tex(RENDER, "./textures/SSGRH0.png");
	weapon->texture_sshotgun[10] = load_tex(RENDER, "./textures/SSGRI0.png");
	weapon->texture_sshotgun[11] = load_tex(RENDER, "./textures/SSGRK0.png");
	weapon->texture_sshotgun[12] = load_tex(RENDER, "./textures/SSGRL0.png");
	weapon->texture_sshotgun[13] = load_tex(RENDER, "./textures/SSGRM0.png");
	weapon->texture_sshotgun[14] = load_tex(RENDER, "./textures/SSGRN0.png");
	weapon->texture_sshotgun[15] = load_tex(RENDER, "./textures/SSGRO0.png");
	weapon->texture_sshotgun[16] = load_tex(RENDER, "./textures/SSGRP0.png");
	weapon->texture_sshotgun[17] = load_tex(RENDER, "./textures/SSGRQ0.png");
	weapon->texture_sshotgun[18] = load_tex(RENDER, "./textures/SSGRR0.png");
	weapon->texture_sshotgun[19] = load_tex(RENDER, "./textures/SSGRS0.png");
	weapon->texture_sshotgun[20] = load_tex(RENDER, "./textures/SSGRT0.png");
	weapon->texture_sshotgun[21] = load_tex(RENDER, "./textures/SSGRU0.png");
	weapon->texture_sshotgun[22] = \
		load_tex(RENDER, "./textures/shotgun_pic.png");
}

void	init_weapon_shotgun(t_weapon *weapon, t_wolf *holder)
{
	weapon->texture_sshotgun[0] = load_tex(RENDER, "./textures/SSGFE0.png");
	weapon->texture_sshotgun[1] = load_tex(RENDER, "./textures/SSGFF0.png");
	weapon->texture_sshotgun[2] = load_tex(RENDER, "./textures/SSGRA0.png");
	weapon->texture_sshotgun[3] = load_tex(RENDER, "./textures/SSGRB0.png");
	init_shotgun_tex(weapon, holder);
	weapon->pistol_shoot = load_chunk("resourses/shotgu.wav");
	SDL_QueryTexture(weapon->texture_sshotgun[0], NULL, NULL, \
					&weapon->tex_w, &weapon->tex_h);
	weapon->frame_w = weapon->tex_w;
	weapon->frame_h = weapon->tex_h;
	weapon->frame = 0;
	weapon->num_frames = 88;
	weapon->pic = 22;
	return ;
}
