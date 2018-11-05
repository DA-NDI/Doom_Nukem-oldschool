/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:49:39 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/26 17:15:51 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_hud_init(t_wolf *holder)
{
	t_hud *hud;

	hud = (t_hud*)malloc(sizeof(t_hud));
	holder->hud = hud;
	hud->hud[0] = load_tex(RENDER, "./resourses/hearts0.png");
	hud->hud[1] = load_tex(RENDER, "./resourses/hearts1.png");
	hud->hud[2] = load_tex(RENDER, "./resourses/hearts2.png");
	hud->hud[3] = load_tex(RENDER, "./resourses/hearts3.png");
	hud->hud[4] = load_tex(RENDER, "./resourses/hearts4.png");
	hud->hud[5] = load_tex(RENDER, "./resourses/hp.png");
	hud->hud[6] = load_tex(RENDER, "./resourses/shield.png");
	hud->hud[7] = load_tex(RENDER, "./resourses/rockets.png");
	hud->hud[8] = load_tex(RENDER, "./resourses/ammo.png");
	hud->hud[9] = load_tex(RENDER, "./resourses/jetpack.png");
	hud->hud[10] = load_tex(RENDER, "./resourses/gun_pointer.png");
	hud->hud[11] = load_tex(RENDER, "./resourses/energy.png");
	hud->hud[12] = load_tex(RENDER, "./resourses/first_aid.png");
	hud->lives = 4;
	hud->hp = 100;
	hud->shield = 0;
	hud->rockets = 5;
	hud->ammo = 25;
	hud->jetpack = 1000;
	hud->level = 1;
	hud->enemy_speed = 0;
}

void		draw_hud_icons(t_wolf *holder)
{
	SDL_RenderCopy(holder->renderer, holder->hud->hud[holder->hud->lives], \
			NULL, &(SDL_Rect){WIDTH / 2 - 48, 5, 96, 18});
	SDL_RenderCopy(holder->renderer, holder->hud->hud[5], \
			NULL, &(SDL_Rect){10, HEIGHT - 25, 20, 18});
	SDL_RenderCopy(holder->renderer, holder->hud->hud[6], \
			NULL, &(SDL_Rect){100, HEIGHT - 25, 20, 18});
	SDL_RenderCopy(holder->renderer, holder->hud->hud[7], \
			NULL, &(SDL_Rect){WIDTH - 120, HEIGHT - 25, 20, 18});
	SDL_RenderCopy(holder->renderer, holder->hud->hud[8], \
			NULL, &(SDL_Rect){WIDTH - 50, HEIGHT - 25, 20, 18});
	SDL_RenderCopy(holder->renderer, holder->hud->hud[9], \
			NULL, &(SDL_Rect){WIDTH - 170, HEIGHT - 25, 20, 18});
	SDL_RenderCopy(holder->renderer, holder->hud->hud[10], \
			NULL, &(SDL_Rect){WIDTH / 2 - 32, HEIGHT / 2 - 32, 64, 64});
	SDL_RenderCopy(holder->renderer, holder->hud->hud[11], \
			NULL, &(SDL_Rect){WIDTH / 2 - 200, HEIGHT - 30, 22, 22});
	SDL_RenderCopy(holder->renderer, holder->hud->hud[12], \
			NULL, &(SDL_Rect){WIDTH / 2 - 250, HEIGHT - 30, 22, 22});
}

void		draw_hud_text(t_wolf *holder, char *hp)
{
	char	*shield;
	char	*rockets;
	char	*ammo;
	char	*jetpack;

	hp = ft_itoa(holder->hud->hp);
	shield = ft_itoa(holder->hud->shield);
	rockets = ft_itoa(holder->hud->rockets);
	ammo = ft_itoa(holder->hud->ammo);
	jetpack = ft_itoa(holder->hud->jetpack);
	draw_text(holder, "Lives:", WIDTH / 2 - 80, 10);
	draw_text(holder, hp, 45, HEIGHT - 22);
	draw_text(holder, shield, 125, HEIGHT - 22);
	draw_text(holder, rockets, WIDTH - 125, HEIGHT - 22);
	draw_text(holder, ammo, WIDTH - 65, HEIGHT - 22);
	draw_text(holder, jetpack, WIDTH - 185, HEIGHT - 22);
	free(hp);
	hp = ft_itoa(holder->hud->level);
	draw_text(holder, "LEVEL: ", WIDTH / 2, HEIGHT - 22);
	draw_text(holder, hp, WIDTH / 2 + 35, HEIGHT - 22);
	free(hp);
	free(shield);
	free(rockets);
	free(ammo);
	free(jetpack);
}

void		draw_hud(t_wolf *holder)
{
	char	*frags;
	char	*aid;
	char	*energy;
	char	*hp;

	frags = ft_itoa(holder->frags);
	hp = NULL;
	energy = ft_itoa(holder->energy);
	aid = ft_itoa(holder->hp);
	draw_hud_icons(holder);
	draw_hud_text(holder, hp);
	draw_text(holder, "Frags: ", 180, HEIGHT - 22);
	draw_text(holder, frags, 210, HEIGHT - 22);
	draw_text(holder, aid, 250, HEIGHT - 22);
	draw_text(holder, energy, 310, HEIGHT - 22);
	free(frags);
	free(aid);
	free(energy);
}
