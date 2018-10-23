/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subaru.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:25:05 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:48:54 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			redraw(t_global *global)
{
	SDL_SetRenderDrawColor(global->renderer, 0, 0, 0, 255);
	SDL_RenderClear(global->renderer);
	if (global->pos == 0 || global->pos == 5)
		put_text("Pick Texture", 165, *global, 1450);
	else if (global->pos == 1)
		put_text("Pick 2 Dots", 165, *global, 1450);
	else if (global->pos == 2 || global->pos == 6)
	{
		put_text("Set Height", 165, *global, 1450);
		put_text(global->text, 685, *global, 1400);
	}
	else if (global->pos == 3)
		put_text("Pick wall", 165, *global, 1450);
	else if (global->pos == 4)
		put_text("EDIT: D, T, H", 165, *global, 1450);
	put_text("Save to file", 805, *global, 1450);
	set_rect_for_texture(global);
	SDL_SetRenderDrawColor(global->renderer, 255, 255, 255, 0);
	draw_grid(*global);
	draw_lines1(*global);
	draw_lines1_rect(*global);
	SDL_RenderPresent(global->renderer);
}

void			chech_for_d_t_h(t_global *global)
{
	if (global->event.type == SDL_KEYUP)
	{
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"D") == 0)
		{
			list_remove(&global->lines, global->lines);
			global->pos = 0;
		}
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"T") == 0)
			global->pos = 5;
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"H") == 0)
			global->pos = 6;
	}
}

void			global_pos_0(t_global *global)
{
	pos_0_pick_tex(global);
}

void			global_pos_1(t_global *global)
{
	pos_1_set_dot(global);
}

void			global_pos_2(t_global *global)
{
	if (global->event.type == SDL_TEXTINPUT)
		strcat(global->text, global->event.text.text);
}
