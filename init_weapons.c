/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 02:23:18 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 02:54:39 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	init_weapon(t_weapon *weapon, t_wolf *holder)
{
	weapon->texture_sshotgun[0] = load_tex(RENDER, "./textures/pistol_1.png");
	weapon->texture_sshotgun[1] = load_tex(RENDER, "./textures/pistol_2.png");
	weapon->texture_sshotgun[2] = load_tex(RENDER, "./textures/pistol_3.png");
	weapon->texture_sshotgun[3] = load_tex(RENDER, "./textures/pistol_4.png");
	weapon->texture_sshotgun[4] = load_tex(RENDER, "./textures/pistol_5.png");
	weapon->texture_sshotgun[5] = load_tex(RENDER, "./textures/pistol_6.png");
	weapon->texture_sshotgun[6] = load_tex(RENDER, "./textures/pistol_7.png");
	weapon->texture_sshotgun[7] = load_tex(RENDER, "./textures/pistol_8.png");
	weapon->texture_sshotgun[8] = load_tex(RENDER, "./textures/pistol_9.png");
	weapon->texture_sshotgun[9] = load_tex(RENDER, "./textures/pistol_10.png");
	weapon->texture_sshotgun[10] = load_tex(RENDER, "./textures/pistol_11.png");
	weapon->texture_sshotgun[11] = load_tex(RENDER, "./textures/pist_pic.png");
	weapon->pistol_shoot = load_chunk("resourses/dsplasma.wav");
	SDL_QueryTexture(weapon->texture_sshotgun[0], NULL, NULL, \
					&weapon->tex_w, &weapon->tex_h);
	weapon->frame_w = weapon->tex_w / 1;
	weapon->frame_h = weapon->tex_h / 1;
	weapon->frame = 0;
	weapon->num_frames = 44;
	weapon->pic = 11;
	return ;
}

void	init_greande_tex(t_weapon *weapon, t_wolf *holder)
{
	weapon->texture_sshotgun[11] = load_tex(RENDER, "./textures/grenade12.png");
	weapon->texture_sshotgun[12] = load_tex(RENDER, "./textures/grenade13.png");
	weapon->texture_sshotgun[13] = load_tex(RENDER, "./textures/grenade14.png");
	weapon->texture_sshotgun[14] = load_tex(RENDER, "./textures/grenade15.png");
	weapon->texture_sshotgun[15] = load_tex(RENDER, "./textures/grenade16.png");
	weapon->texture_sshotgun[16] = load_tex(RENDER, "./textures/grenade17.png");
	weapon->texture_sshotgun[17] = load_tex(RENDER, "./textures/grenade18.png");
	weapon->texture_sshotgun[18] = load_tex(RENDER, "./textures/grenade19.png");
	weapon->texture_sshotgun[19] = load_tex(RENDER, "./textures/grenade20.png");
	weapon->texture_sshotgun[20] = load_tex(RENDER, "./textures/grenade21.png");
	weapon->texture_sshotgun[21] = load_tex(RENDER, "./textures/grenade22.png");
	weapon->texture_sshotgun[22] = load_tex(RENDER, "./textures/grenade23.png");
	weapon->texture_sshotgun[23] = load_tex(RENDER, "./textures/grenade24.png");
	weapon->texture_sshotgun[24] = load_tex(RENDER, "./textures/grenade25.png");
	weapon->texture_sshotgun[25] = load_tex(RENDER, "./textures/grenade26.png");
	weapon->texture_sshotgun[26] = \
		load_tex(RENDER, "./textures/grenade_pic.png");
}

void	init_weapon_grenade(t_weapon *weapon, t_wolf *holder)
{
	weapon->texture_sshotgun[0] = load_tex(RENDER, "./textures/grenade1.png");
	weapon->texture_sshotgun[1] = load_tex(RENDER, "./textures/grenade2.png");
	weapon->texture_sshotgun[2] = load_tex(RENDER, "./textures/grenade3.png");
	weapon->texture_sshotgun[3] = load_tex(RENDER, "./textures/grenade4.png");
	weapon->texture_sshotgun[4] = load_tex(RENDER, "./textures/grenade5.png");
	weapon->texture_sshotgun[5] = load_tex(RENDER, "./textures/grenade6.png");
	weapon->texture_sshotgun[6] = load_tex(RENDER, "./textures/grenade7.png");
	weapon->texture_sshotgun[7] = load_tex(RENDER, "./textures/grenade8.png");
	weapon->texture_sshotgun[8] = load_tex(RENDER, "./textures/grenade9.png");
	weapon->texture_sshotgun[9] = load_tex(RENDER, "./textures/grenade10.png");
	weapon->texture_sshotgun[10] = \
		load_tex(RENDER, "./textures/grenade11.png");
	init_greande_tex(weapon, holder);
	weapon->pistol_shoot = load_chunk("resourses/grenade.wav");
	SDL_QueryTexture(weapon->texture_sshotgun[0], NULL, NULL, \
					&weapon->tex_w, &weapon->tex_h);
	weapon->frame_w = weapon->tex_w;
	weapon->frame_h = weapon->tex_h;
	weapon->frame = 0;
	weapon->num_frames = 102;
	weapon->pic = 26;
	return ;
}

void	init_weapon_demon(t_weapon *weapon, t_wolf *holder)
{
	weapon->texture_sshotgun[0] = load_tex(RENDER, "./textures/demon1.png");
	weapon->texture_sshotgun[1] = load_tex(RENDER, "./textures/demon2.png");
	weapon->texture_sshotgun[2] = load_tex(RENDER, "./textures/demon3.png");
	weapon->texture_sshotgun[3] = load_tex(RENDER, "./textures/demon4.png");
	weapon->texture_sshotgun[4] = load_tex(RENDER, "./textures/demon5.png");
	weapon->texture_sshotgun[5] = load_tex(RENDER, "./textures/demon6.png");
	weapon->texture_sshotgun[6] = load_tex(RENDER, "./textures/demon7.png");
	weapon->texture_sshotgun[7] = load_tex(RENDER, "./textures/demon8.png");
	weapon->texture_sshotgun[8] = load_tex(RENDER, "./textures/demon9.png");
	weapon->texture_sshotgun[9] = load_tex(RENDER, "./textures/demon10.png");
	weapon->texture_sshotgun[10] = load_tex(RENDER, "./textures/demon11.png");
	weapon->texture_sshotgun[11] = load_tex(RENDER, "./textures/demon12.png");
	weapon->texture_sshotgun[12] = load_tex(RENDER, "./textures/demon13.png");
	weapon->texture_sshotgun[13] = load_tex(RENDER, "./textures/demon14.png");
	weapon->texture_sshotgun[14] = \
		load_tex(RENDER, "./textures/demon_pic.png");
	weapon->pistol_shoot = load_chunk("resourses/demon.wav");
	SDL_QueryTexture(weapon->texture_sshotgun[0], NULL, NULL, \
					&weapon->tex_w, &weapon->tex_h);
	weapon->frame_w = weapon->tex_w;
	weapon->frame_h = weapon->tex_h;
	weapon->frame = 0;
	weapon->num_frames = 52;
	weapon->pic = 14;
	return ;
}
