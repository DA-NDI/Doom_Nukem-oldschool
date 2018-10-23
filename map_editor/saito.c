/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saito.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:25:41 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:37:56 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			global_pos_2_write(t_global *global)
{
	if (global->event.type == SDL_KEYUP)
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"Backspace") == 0)
			global->text[strlen(global->text) - 1] = '\0';
	if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
	"Return") == 0)
	{
		if ((global->lines->height = abs(atoi(global->text))) > 300)
			global->lines->height = 300;
		if (global->pos != 6)
			global->lines->texture_number = global->current_texture;
		bzero(global->text, strlen(global->text));
		global->pos = 0;
	}
}

int				find_closest_wall(t_global *global)
{
	t_line *cur;

	cur = global->lines;
	while (cur)
	{
		if (((cur->x1 - 100) / global->xmode) == ((global->x1 - 100) /
		global->xmode) &&
			((cur->y1 - 100) / global->ymode) == ((global->y1 - 100) /
			global->ymode))
		{
			global->to_edit = cur;
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

void			push_to_front(t_line **head, t_line *global)
{
	t_line *q;

	q = malloc(sizeof(t_line));
	q->x1 = global->x1;
	q->y1 = global->y1;
	q->x2 = global->x2;
	q->y2 = global->y2;
	q->height = global->height;
	q->texture_number = global->texture_number;
	q->next = *head;
	*head = q;
}

void			global_pos_3_edit(t_global *global)
{
	if (global->event.type == SDL_MOUSEBUTTONDOWN &&
	(SDL_GetMouseState(&global->x1, &global->y1) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		if (dot_in_map(global->x1, global->y1))
			return ;
		if (find_closest_wall(global))
		{
			global->pos = 4;
			push_to_front(&global->lines, global->to_edit);
			list_remove(&global->lines, global->to_edit);
		}
	}
}

void			draw_grid(t_global global)
{
	int x;
	int y;

	x = 100;
	y = 100;
	while (x < 1300)
	{
		y = 100;
		while (y < 900)
		{
			SDL_RenderDrawLine(global.renderer, x, y, x + global.xmode, y);
			SDL_RenderDrawLine(global.renderer, x, y, x, y + global.ymode);
			y += global.ymode;
		}
		x += global.xmode;
	}
}
