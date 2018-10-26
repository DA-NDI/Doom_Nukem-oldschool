/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:38:20 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/26 21:44:24 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#define SEL_3 (holder->start->play_select == 3)

void		ft_draw_menu_2(t_wolf *holder)
{
	if (holder->starting == 2)
	{
		SDL_RenderCopy(holder->renderer, START_SCR, NULL, NULL);
		draw_text(holder, "Choose Difficulty", WIDTH / 2, HEIGHT / 2 + 70);
		draw_text(holder, " > Normal", WIDTH / 2 - 10, HEIGHT / 2);
		draw_text(holder, "	  Insane", WIDTH / 2 - 10, HEIGHT / 2 + 15);
		draw_text(holder, "	  Brutal", WIDTH / 2 - 10, HEIGHT / 2 + 30);
		draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
		SDL_RenderPresent(holder->renderer);
	}
}

void		ft_draw_menu_brutal(t_wolf *holder)
{
	SDL_RenderCopy(holder->renderer, START_SCR, NULL, NULL);
	draw_text(holder, "Choose Difficulty", WIDTH / 2, HEIGHT / 2 + 70);
	draw_text(holder, "	  Normal", WIDTH / 2 - 10, HEIGHT / 2);
	draw_text(holder, "	  Insane", WIDTH / 2 - 10, HEIGHT / 2 + 15);
	draw_text(holder, " > Brutal", WIDTH / 2 - 10, HEIGHT / 2 + 30);
	draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
	holder->start->play_select = 4;
	SDL_RenderPresent(holder->renderer);
}

void		ft_check_menu_2(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_DOWN] && holder->starting == 2 &&\
	holder->start->play_select == 2)
	{
		SDL_RenderCopy(holder->renderer, START_SCR, NULL, NULL);
		draw_text(holder, "Choose Difficulty", WIDTH / 2, HEIGHT / 2 + 70);
		draw_text(holder, "	  Normal", WIDTH / 2 - 10, HEIGHT / 2);
		draw_text(holder, " > Insane", WIDTH / 2 - 10, HEIGHT / 2 + 15);
		draw_text(holder, "	  Brutal", WIDTH / 2 - 10, HEIGHT / 2 + 30);
		draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
		holder->start->play_select = 3;
		SDL_RenderPresent(holder->renderer);
	}
	else if (keystate[SDL_SCANCODE_UP] && holder->starting == 2)
	{
		SDL_RenderCopy(holder->renderer, START_SCR, NULL, NULL);
		draw_text(holder, "Choose Difficulty", WIDTH / 2, HEIGHT / 2 + 70);
		draw_text(holder, " > Normal", WIDTH / 2 - 10, HEIGHT / 2);
		draw_text(holder, "	  Insane", WIDTH / 2 - 10, HEIGHT / 2 + 15);
		draw_text(holder, "	  Brutal", WIDTH / 2 - 10, HEIGHT / 2 + 30);
		draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
		holder->start->play_select = 2;
		SDL_RenderPresent(holder->renderer);
	}
	else if (keystate[SDL_SCANCODE_DOWN] && holder->starting == 2 && SEL_3)
		ft_draw_menu_brutal(holder);
}

void		ft_check_other(t_wolf *holder, const Uint8 *keystate)
{
	if (keystate[SDL_SCANCODE_DOWN] && holder->starting == 1)
	{
		SDL_RenderCopy(holder->renderer, START_SCR, NULL, NULL);
		draw_text(holder, "	  Play", WIDTH / 2 - 10, HEIGHT / 2);
		draw_text(holder, " > Quit", WIDTH / 2 - 10, HEIGHT / 2 + 15);
		draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
		holder->start->play_select = 0;
		SDL_RenderPresent(holder->renderer);
	}
	else if (keystate[SDL_SCANCODE_UP] && holder->starting == 1)
	{
		SDL_RenderCopy(holder->renderer, START_SCR, NULL, NULL);
		draw_text(holder, " > Play", WIDTH / 2 - 10, HEIGHT / 2);
		draw_text(holder, "	  Quit", WIDTH / 2 - 10, HEIGHT / 2 + 15);
		draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
		holder->start->play_select = 1;
		SDL_RenderPresent(holder->renderer);
	}
	ft_check_menu_2(holder, keystate);
}
