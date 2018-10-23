/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sagiri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:24:59 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:49:43 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			add_texture2(t_global *global)
{
	global->texture[10] = IMG_LoadTexture(global->renderer,
	"../sprites/ammo.png");
	global->texture[11] = IMG_LoadTexture(global->renderer,
	"../sprites/arcade_end1.png");
	global->texture[12] = IMG_LoadTexture(global->renderer,
	"../sprites/car_256_5.png");
	global->texture[13] = IMG_LoadTexture(global->renderer,
	"../sprites/cola.png");
	global->texture[14] = IMG_LoadTexture(global->renderer,
	"../sprites/pepsi.png");
	global->texture[15] = IMG_LoadTexture(global->renderer,
	"../sprites/potion.png");
}

void			add_texture(t_global *global)
{
	global->texture[0] = IMG_LoadTexture(global->renderer,
	"../texture/fence_wire2.png");
	global->texture[1] = IMG_LoadTexture(global->renderer,
	"../texture/portal.png");
	global->texture[2] = IMG_LoadTexture(global->renderer,
	"../texture/wall_wire_blue.png");
	global->texture[3] = IMG_LoadTexture(global->renderer,
	"../texture/brick_lblue1.png");
	global->texture[4] = IMG_LoadTexture(global->renderer,
	"../texture/floor_wire_violet.png");
	global->texture[5] = IMG_LoadTexture(global->renderer,
	"../texture/light_off.png");
	global->texture[6] = IMG_LoadTexture(global->renderer,
	"../texture/fury_poster.png");
	global->texture[7] = IMG_LoadTexture(global->renderer,
	"../texture/brick_pink2.png");
	global->texture[8] = IMG_LoadTexture(global->renderer,
	"../texture/wall_texture11.png");
	global->texture[9] = IMG_LoadTexture(global->renderer,
	"../texture/light_on.png");
	add_texture2(global);
}

void			init_sdl(t_global *global)
{
	t_tools ij;

	ij.x = -1;
	bzero(global->text, 9);
	global->map = (unsigned int**)malloc(global->mode * sizeof(unsigned int*));
	while (++ij.x < global->mode)
	{
		global->map[ij.x] = (unsigned int*)malloc(global->mode
		* sizeof(unsigned int));
		ij.y = -1;
		while (++ij.y < global->mode)
			global->map[ij.x][ij.y] = 0;
	}
	global->window = SDL_CreateWindow("MAP",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	global->renderer = SDL_CreateRenderer(global->window,
		-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	global->x2 = 110;
	global->y2 = 110;
	global->drawing = 0;
	TTF_Init();
	global->font = TTF_OpenFont("font.ttf", 50);
	add_texture(global);
	global->done = SDL_FALSE;
}

void			pos_0_pick_tex(t_global *global)
{
	if (global->event.type == SDL_KEYUP)
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"E") == 0)
			global->pos = 3;
	if (global->event.type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_GetMouseState(&global->x1, &global->y1);
		if ((global->current_texture = in_texture(global->x1, global->y1)) >= 0)
		{
			global->pos = 1;
		}
		if (in_save_to_file(global->x1, global->y1) > 0)
		{
			make_exit(&global->lines, global);
			global->done = SDL_TRUE;
		}
	}
}

void			pos_1_set_dot(t_global *global)
{
	if (global->event.type == SDL_MOUSEBUTTONDOWN &&
	(SDL_GetMouseState(&global->x1, &global->y1) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		if ((dot_in_map(global->x1, global->y1)) ||
		(dot_in_map(global->x2, global->y2)))
			return ;
		if (!global->drawing)
		{
			global->x2 = global->x1;
			global->y2 = global->y1;
			global->drawing = 1;
		}
		else
		{
			if (global->z)
				push(&global->lines, *global);
			else
			{
				global->lines = create(*global);
				global->z = 1;
			}
			global->pos = 2;
			global->drawing = 0;
		}
	}
}
