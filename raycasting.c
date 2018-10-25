/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 22:01:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/24 21:33:54 by avolgin          ###   ########.fr       */
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
	int				tmp;

	tmp = -1;
	if (holder->frags >= 1)
	{
		holder->hud->level++;
		i = -1;
		while (holder->map[++i])
			free(holder->map[i]);
		i = -1;
		while (holder->height_map[++i])
			free(holder->height_map[i]);
		if (holder->hud->level == 2)
			holder->map = ft_create_map("./maps/2", holder);
		else
			holder->map = ft_create_map("./maps/2", holder);
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
		if (fabsf(holder->sprite[a + 7]->x - P_X) < 1 && \
			fabsf(holder->sprite[a + 7]->y - P_Y) < 1 && \
			holder->sprite[a + 7]->is_sprite)
		{
			holder->energy += 10;
			holder->sprite[a + 7]->is_sprite = 0;
		}
	}
	a = -1;
	while (++a < holder->sprite_tex[3]->amount)
	{
		if (fabsf(holder->sprite[a + 10]->x - P_X) < 1 && \
			fabsf(holder->sprite[a + 10]->y - P_Y) < 1 && \
			holder->sprite[a + 10]->is_sprite)
		{
			holder->hud->ammo += 5;
			holder->sprite[a + 10]->is_sprite = 0;
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
unsigned int buffer[holder->height][holder->width], int num)
{
	int			a;
	t_sprite	*sprites[20];

	a = -1;
	raycasting_loop(holder, holder->camera, -1, buffer);
	while (++a < holder->sprite_tex[0]->amount)
		sprites[num++] = CAR;
	a = -1;
	while (++a < holder->sprite_tex[2]->amount)
		sprites[num++] = ARC;
	ft_draw_sprites(holder, holder->camera, buffer, holder->sprite[0]);
	a = -1;
	while (++a < holder->sprite_tex[6]->amount && a < 3)
		sprites[num++] = KOLA;
	a = -1;
	while (++a < holder->sprite_tex[5]->amount && a < 3)
		sprites[num++] = PEPS;
	a = -1;
	while (++a < holder->sprite_tex[4]->amount && a < 3)
		sprites[num++] = POT;
	a = -1;
	while (++a < holder->sprite_tex[3]->amount && a < 3)
		sprites[num++] = AMO;
	drawing_sorting_sprites(holder, sprites, num, buffer);
}

void	ft_raycasting(t_wolf *holder, int x)
{
	static unsigned int	buffer[768][1024];
	static int			i = 0;

	while (holder->running)
	{
		ft_raycasting_2(holder, buffer, 0);
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
