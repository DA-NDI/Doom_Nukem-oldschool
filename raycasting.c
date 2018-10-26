/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 22:01:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/26 13:22:26 by avolgin          ###   ########.fr       */
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
	static unsigned int	buffer[768][1024];
	static int			i = 0;

	while (holder->running)
	{
		ft_check_next_level(holder);
		raycasting_loop(holder, holder->camera, -1, buffer);
		drawing_sorting_sprites(holder, SORTED, holder->sprites->num, buffer);
		i = ft_raycasting_3(holder, i);
		if (!holder->pause && !holder->starting && holder->running)
		{
			SDL_UpdateTexture(holder->screen, NULL, buffer[0], WIDTH << 2);
			x = -1;
			while (++x < holder->height)
				ft_zero_fill(buffer[x], holder->width);
			SDL_RenderClear(holder->renderer);
			draw_skybox(holder, holder->camera);
			SDL_RenderCopy(holder->renderer, holder->screen, NULL, NULL);
			draw_weapon(holder->weapon, holder);
			draw_fps(holder, holder->camera->font);
			draw_hud(holder);
			SDL_RenderPresent(holder->renderer);
		}
		ft_close_loop(holder, holder->camera);
	}
}
