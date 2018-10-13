/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:49:31 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/20 06:10:58 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#define WEAPON_TEX weapon[G]->texture_sshotgun

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
	weapon->num_frames = 104;
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

/*
** for all in one horizontal sprite
** weapon->rect.x += weapon->frame_w * weapon->frame;
** if (weapon->rect.x >= weapon->tex_w)
**	weapon->rect.x = 0;
*/

void	draw_weapon(t_weapon *weapon[], t_wolf *holder)
{
	SDL_Rect dest_r;

	dest_r.x = (G != 2) ? holder->width / 2 - (weapon[G]->tex_w / 2) : \
		WIDTH / 6 - (weapon[G]->tex_w);
	dest_r.y = holder->height - (weapon[G]->tex_h << 2);
	dest_r.w = weapon[G]->tex_w << 2;
	dest_r.h = weapon[G]->tex_h << 2;
	weapon[G]->rect.x = 0;
	weapon[G]->rect.y = 0;
	weapon[G]->rect.w = weapon[G]->frame_w;
	weapon[G]->rect.h = weapon[G]->frame_h;
	weapon[G]->frame += (holder->shooting) ? 1 : 0;
	if (weapon[G]->frame == weapon[G]->num_frames)
	{
		weapon[G]->frame = 0;
		holder->shooting = 0;
	}
	if (holder->shooting && weapon[G]->frame)
		SDL_RenderCopy(holder->renderer, \
		WEAPON_TEX[weapon[G]->frame / 4], &weapon[G]->rect, &dest_r);
	else
		SDL_RenderCopy(holder->renderer, weapon[G]->texture_sshotgun[0], \
		&(SDL_Rect){0, 0, weapon[G]->frame_w, weapon[G]->frame_h}, &dest_r);
	SDL_RenderCopy(holder->renderer, weapon[G]->texture_sshotgun[PIC], NULL, \
&(SDL_Rect){WIDTH - 60, 0, weapon[G]->frame_w >> 2, weapon[G]->frame_h >> 2});
}
