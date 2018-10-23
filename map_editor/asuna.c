/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asuna.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:25:13 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:35:38 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			set_rect_for_texture(t_global *global)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 1375;
	y = 250;
	while (i < 16)
	{
		if (i == 4 || i == 8 || i == 12)
		{
			y += 100;
			x = 1375;
		}
		global->texture_rect[i].x = x;
		global->texture_rect[i].y = y;
		global->texture_rect[i].w = 75;
		global->texture_rect[i].h = 75;
		if (i < 16)
			SDL_RenderCopy(global->renderer,
		global->texture[i], NULL, &global->texture_rect[i]);
		x += 100;
		i++;
	}
}

t_line			*create(t_global global)
{
	t_line *q;

	q = malloc(sizeof(t_line));
	q->x1 = global.x1;
	q->y1 = global.y1;
	q->x2 = global.x2;
	q->y2 = global.y2;
	q->texture_number = global.current_texture;
	q->next = NULL;
	return (q);
}

void			push(t_line **head, t_global global)
{
	t_line *new;

	new = create(global);
	new->next = *head;
	*head = new;
}

SDL_Rect		*create_rect(int x, int y, int w, int h)
{
	SDL_Rect *new;

	new = (SDL_Rect*)(malloc(sizeof(SDL_Rect)));
	new->x = x;
	new->y = y;
	new->w = w;
	new->h = h;
	return (new);
}

void			put_text(char *s, int ys, t_global global, int xs)
{
	int				x;
	int				y;
	SDL_Color		color;
	SDL_Surface		*surface;
	SDL_Rect		*link;

	x = 30;
	y = 30;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	surface = TTF_RenderText_Solid(global.font, s, color);
	global.textur = SDL_CreateTextureFromSurface(global.renderer, surface);
	SDL_QueryTexture(global.textur, NULL, NULL, &x, &y);
	link = create_rect(xs, ys, x, y);
	SDL_RenderCopy(global.renderer, global.textur, NULL, link);
	free(link);
	SDL_FreeSurface(surface);
}
