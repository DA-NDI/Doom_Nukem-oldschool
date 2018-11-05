/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:38:41 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 22:49:16 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_close(t_wolf *holder)
{
	Mix_FreeChunk(holder->weapon[0]->pistol_shoot);
	Mix_FreeChunk(holder->weapon[1]->pistol_shoot);
	holder->weapon[0]->pistol_shoot = NULL;
	holder->weapon[1]->pistol_shoot = NULL;
	SDL_DestroyRenderer(holder->renderer);
	SDL_DestroyWindow(holder->window);
	holder->running = 0;
	free(holder->start);
	TTF_Quit();
	SDL_Quit();
	exit(0);
}

void		ft_print_error(char *str)
{
	ft_putendl(str);
	exit(1);
}
