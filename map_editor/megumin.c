/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megumin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:25:23 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:36:59 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			draw_lines1_rect(t_global global)
{
	SDL_Rect *link;

	link = create_rect(100, 100, 1200, 800);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
	link = create_rect(1375, 125, 375, 100);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
	link = create_rect(1375, 775, 375, 100);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
	link = create_rect(1375, 650, 375, 100);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
	link = create_rect(1350, 100, 425, 800);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
}

void			dot_in_texture(int x, int y, t_global *global, t_line *cur)
{
	SDL_Rect	*link;
	t_tools		xy;

	xy.x = 100;
	while (xy.x < 1300)
	{
		xy.y = 100;
		while (xy.y < 900)
		{
			if (x > xy.x && y > xy.y
				&& x < xy.x + global->xmode && y < xy.y + global->ymode)
			{
				link = create_rect(xy.x, xy.y, global->xmode, global->ymode);
				SDL_RenderCopy(global->renderer,
			global->texture[cur->texture_number], NULL, link);
				global->map[(xy.x - 100) / global->xmode][(xy.y - 100) /
				global->ymode] = ((((unsigned int)(cur->texture_number + 1))
				<< 16) |
				(unsigned int)(cur->height));
				free(link);
			}
			xy.y += global->ymode;
		}
		xy.x += global->xmode;
	}
}

void			draw_lines1(t_global global)
{
	t_line	*cur;
	int		x;
	int		y;
	float	t;

	cur = global.lines;
	while (cur)
	{
		t = 0;
		while (t < 1)
		{
			x = cur->x1 * (1. - t) + cur->x2 * t;
			y = cur->y1 * (1. - t) + cur->y2 * t;
			dot_in_texture(x, y, &global, cur);
			t += .01;
		}
		cur = cur->next;
	}
}

int				in_texture(int x, int y)
{
	int i;
	int x1;
	int y1;

	i = 0;
	x1 = 1375;
	y1 = 250;
	while (i < 16)
	{
		if (i == 4 || i == 8 || i == 12 || i == 16)
		{
			y1 += 100;
			x1 = 1375;
		}
		if (x > x1 && y > y1 && x <= x1 + 75 && y <= y1 + 75)
			return (i);
		i++;
		x1 += 100;
	}
	return (-1);
}

int				dot_in_map(int x1, int y1)
{
	if (x1 > MAP_REC_X && y1 > MAP_REC_Y
		&& x1 < MAP_REC_W && y1 < MAP_REC_H)
		return (0);
	else
		return (1);
}
