/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:49:31 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 02:24:35 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#define WEAPON_TEX weapon[G]->texture_sshotgun

/*
** for all in one horizontal sprite
** weapon->rect.x += weapon->frame_w * weapon->frame;
** if (weapon->rect.x >= weapon->tex_w)
**	weapon->rect.x = 0;
** {0, 0}
*/

void	init_coords(int arr[0][40])
{
	arr[0][15] = 61;
	arr[0][16] = 48;
	arr[0][17] = 33;
	arr[0][18] = 0;
	arr[0][19] = 0;
	arr[0][20] = -48;
	arr[0][21] = 33;
	arr[0][22] = -87;
	arr[0][23] = 61;
	arr[0][24] = -131;
	arr[0][25] = 97;
	arr[0][26] = -160;
	arr[0][27] = 134;
	arr[0][28] = -181;
	arr[0][29] = 175;
	arr[0][30] = -160;
	arr[0][31] = 134;
	arr[0][32] = -131;
	arr[0][33] = 97;
	arr[0][34] = -87;
	arr[0][35] = 61;
	arr[0][36] = -48;
	arr[0][37] = 33;
	arr[0][38] = 0;
	arr[0][39] = 0;
}

void	move_weapon(t_weapon *weapon[], t_wolf *holder, SDL_Rect *dest_r)
{
	static int	i = 0;
	static int	a = 0;
	static int	arr[1][40] = {{48, 33, 87, 61, 131, 97, 160, 134, 181, 175}};

	init_coords(&(arr[0]));
	arr[0][10] = 160;
	arr[0][11] = 134;
	arr[0][12] = 131;
	arr[0][13] = 97;
	arr[0][14] = 87;
	if ((!holder->keys.w && !holder->keys.s && !holder->keys.a && \
		!holder->keys.d) || holder->shooting)
		i = 0;
	dest_r->x = (G != 2) ? holder->width / 2 - (weapon[G]->tex_w / 2)\
		+ arr[0][i] : WIDTH / 6 - (weapon[G]->tex_w);
	dest_r->y = holder->height - (weapon[G]->tex_h << 2) + arr[0][i + 1];
	if (a++ % 3 == 0)
		i += 2;
	if (i == 40)
		i = 0;
}

void	draw_weapon(t_weapon *weapon[], t_wolf *holder)
{
	SDL_Rect		dest_r;

	move_weapon(weapon, holder, &dest_r);
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
