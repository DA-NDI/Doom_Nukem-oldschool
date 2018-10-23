/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naruto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:38:57 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:39:16 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			global_pos_5(t_global *global)
{
	global->current_texture = -1;
	pos_0_pick_tex(global);
	if (global->current_texture >= 0)
	{
		global->lines->texture_number = global->current_texture;
		global->pos = 0;
	}
}

void			event(t_global *global)
{
	if (global->event.type == SDL_QUIT)
		global->done = SDL_TRUE;
	if (global->pos == 0)
		global_pos_0(global);
	else if (global->pos == 1)
		global_pos_1(global);
	else if ((global->pos == 2 || global->pos == 6) &&
	strlen(global->text) <= 2)
		global_pos_2(global);
	if (global->pos == 2 || global->pos == 6)
		global_pos_26(global);
	if (global->pos == 3)
		global_pos_3(global);
	if (global->pos == 4)
	{
		chech_for_d_t_h(global);
		redraw(global);
	}
	if (global->pos == 5)
		global_pos_5(global);
	redraw(global);
}

void			loop(t_global global)
{
	while (!global.done)
	{
		while (SDL_PollEvent(&global.event))
			event(&global);
	}
}

int				words_len(char **cords)
{
	int i;

	i = 0;
	while (*cords)
	{
		cords++;
		i++;
	}
	return (i);
}

void			free_words(char **words)
{
	int i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	words = NULL;
}
