/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:07:26 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 16:15:56 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	draw_skybox_2(t_wolf *holder, SDL_Rect *dstrec, SDL_Rect *srcrec)
{
	srcrec->y = 0;
	srcrec->h = 768;
	dstrec->x = 0;
	dstrec->y = -(int)holder->height / 2 +\
	385 + holder->updown + holder->extra_updown;
	dstrec->h = 768;
	dstrec->w = holder->width;
}

void	draw_skybox(t_wolf *holder, t_camera *camera)
{
	SDL_Rect		dstrec;
	SDL_Rect		srcrec;
	int				w;
	int				h;

	SDL_QueryTexture(camera->skybox_tex[TEX_NUM], NULL, NULL, &w, &h);
	srcrec.x = (TEX_NUM != 0) ? 0 : w / 2;
	if (TEX_NUM != 0)
	{
		srcrec.x += (DIR_Y >= 0) ? ((atan2(DIR_Y, DIR_X) / 3.14) * 180) * \
		(w / 360) : (360 + (atan2(DIR_Y, DIR_X) / 3.14) * 180) * (w / 360);
	}
	else
		srcrec.x -= (DIR_Y >= 0) ? ((atan2(DIR_Y, DIR_X) / 3.14) * 180) * \
		(w / 360) : (360 + (atan2(DIR_Y, DIR_X) / 3.14) * 180) * (w / 360);
	srcrec.w = (TEX_NUM != 0) ? w >> 2 : w >> 1;
	draw_skybox_2(holder, &dstrec, &srcrec);
	SDL_RenderCopy(RENDER, camera->skybox_tex[TEX_NUM], &srcrec, &dstrec);
	if (TEX_NUM == 0)
		SDL_RenderCopy(holder->renderer, camera->skybox_tex[1], NULL, &dstrec);
}
