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
		holder->map = ft_create_map("./maps/map2.txt", holder);
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

void 	ft_swap_i(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void 	ft_swap_f(float *a, float *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void 	ft_sort_sprite(t_wolf *holder, t_sprite **sprites, int i, int num)
{
	int 	order[30];
	float 	dist[30];

	while (++i < num)
    {
      order[i] = i;
      dist[i] = ((P_X - sprites[i]->x) * (P_X - sprites[i]->x) + (P_Y - sprites[i]->y) * (P_Y - sprites[i]->y)); //sqrt not taken, unneeded
    }
	int gap = num;
	int swapped = 0;
	while(gap > 1 || swapped)
	{
    //shrink factor 1.3
    	gap = (gap * 10) / 13;
    	if(gap == 9 || gap == 10)
    		gap = 11;
    	if (gap < 1)
    		gap = 1;
    	swapped = 0;
    	for(int i = 0; i < num - gap; i++)
    	{
      		int j = i + gap;
      		if(dist[i] < dist[j])
      		{
        		ft_swap_f(&dist[i], &dist[j]);
        		ft_swap_i(&order[i], &order[j]);
        		swapped = 1;
      		}
    	}
  	}
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
