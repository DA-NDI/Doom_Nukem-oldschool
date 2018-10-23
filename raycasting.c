/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 22:01:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 15:52:50 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>
#define CAR holder->sprite[a + 2]
#define AMO holder->sprite[a + 10]
#define PEPS holder->sprite[a + 16]
#define KOLA holder->sprite[a + 19]
#define POT holder->sprite[a + 13]
#define ARC holder->sprite[a + 7]

void	ft_check_next_level(t_wolf *holder)
{
	int				i;
	static char		*map[50];
	int				tmp;

	tmp = -1;
	map[1] = "./maps/map2.txt";
	if (holder->frags >= 5)
	{
		holder->hud->level = 2;
		i = -1;
		while (holder->map[++i])
			free(holder->map[i]);
		i = -1;
		while (holder->height_map[++i])
			free(holder->height_map[i]);
		holder->map = ft_create_map(map, holder);
		holder->ceiling = 0;
		holder->frags = 0;
		while (++tmp < holder->sprite_tex[0]->amount)
			free(holder->sprite[tmp + 2]);
		reload_sprites(holder);
	}
}

void	ft_check_pickups(t_wolf *holder)
{
	int a;

	a = -1;
	while (++a < holder->sprite_tex[2]->amount)
	{
		if (fabsf(holder->sprite[a + 7]->x - P_X) < 0.5 && \
			fabsf(holder->sprite[a + 7]->y - P_Y) < 0.5)
		{
			holder->energy++;
			holder->sprite[a + 7]->is_alive = 0;
		}
	}
	a = -1;
	while (++a < holder->sprite_tex[3]->amount)
	{
		if (fabsf(holder->sprite[a + 10]->x - P_X) < 1 && \
			fabsf(holder->sprite[a + 10]->y - P_Y) < 1)
		{
			holder->hud->ammo++;
			holder->sprite[a + 10]->is_alive = 0;
		}
	}
	ft_check_pickups2(holder, -1);
}

int		ft_raycasting_3(t_wolf *holder, int i)
{
	int a;

	a = -1;
	if ((++i % 16) == 0)
	{
		while (++a < holder->sprite_tex[0]->amount)
			ft_move_boss(holder, holder->sprite[a + 2]);
	}
	if ((i % 2) == 0)
	{
		ft_move_bullet(holder, holder->sprite[0]);
		ft_move_bullet(holder, holder->sprite[1]);
	}
	return (i);
}

void	ft_raycasting_2(t_wolf *holder,\
unsigned int buffer[holder->height][holder->width])
{
	int a;

	a = -1;
	holder->frame_start = SDL_GetTicks();
	holder->current_height = holder->height_map[(int)P_Y][(int)P_X];
	holder->current_height = (holder->current_height > 300) ? 0 : 0;
	raycasting_loop(holder, holder->camera, -1, buffer);
	while (++a < holder->sprite_tex[0]->amount)
		ft_draw_sprites(holder, holder->camera, buffer, CAR);
	a = -1;
	while (++a < holder->sprite_tex[2]->amount)
		ft_draw_sprites(holder, holder->camera, buffer, ARC);
	ft_draw_sprites(holder, holder->camera, buffer, holder->sprite[0]);
	a = -1;
	while (++a < holder->sprite_tex[6]->amount && a < 3)
		ft_draw_sprites(holder, holder->camera, buffer, KOLA);
	a = -1;
	while (++a < holder->sprite_tex[5]->amount && a < 3)
		ft_draw_sprites(holder, holder->camera, buffer, PEPS);
	a = -1;
	while (++a < holder->sprite_tex[4]->amount && a < 3)
		ft_draw_sprites(holder, holder->camera, buffer, POT);
	a = -1;
	while (++a < holder->sprite_tex[3]->amount && a < 3)
		ft_draw_sprites(holder, holder->camera, buffer, AMO);
}

void	ft_raycasting(t_wolf *holder, int x)
{
	static unsigned int	buffer[768][1024];
	static int			i = 0;

	while (holder->running)
	{
		ft_raycasting_2(holder, buffer);
		ft_check_pickups(holder);
		i = ft_raycasting_3(holder, i);
		ft_check_next_level(holder);
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
