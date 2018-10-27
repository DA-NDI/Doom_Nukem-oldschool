/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 22:01:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 05:08:03 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

int		ft_raycasting_3(t_wolf *holder, int i)
{
	int a;

	a = -1;
	if ((++i % 16) == 0)
	{
		while (++a < holder->sprite_tex[0]->amount)
			ft_move_boss(holder, CAR);
	}
	if ((i % 2) == 0)
	{
		ft_move_bullet(holder, holder->sprite[0]);
		ft_move_bullet(holder, holder->sprite[1]);
	}
	return (i);
}

void	ft_raycasting(t_wolf *holder, int x)
{
	static int		i = 0;
	unsigned int	*buffer;

	while (holder->running)
	{
		if (SDL_LockTexture(holder->screen, 0, (void**)&buffer, &holder->pitch))
			ft_print_error("locking failed\n");
		x = -1;
		while (++x < holder->height * holder->width)
			buffer[x] = 0;
		ft_check_next_level(holder);
		raycasting_loop(holder, holder->camera, -1, buffer);
		drawing_sorting_sprites(holder, SORTED, holder->sprites->num, buffer);
		i = ft_raycasting_3(holder, i);
		if (!holder->pause && !holder->starting && holder->running)
		{
			SDL_RenderClear(holder->renderer);
			draw_skybox(holder, holder->camera);
			SDL_RenderCopy(holder->renderer, holder->screen, NULL, NULL);
			draw_weapon(holder->weapon, holder);
			draw_fps(holder, holder->camera->font);
			draw_hud(holder);
			SDL_RenderPresent(holder->renderer);
		}
		SDL_UnlockTexture(holder->screen);
		ft_close_loop(holder, holder->camera);
	}
}
