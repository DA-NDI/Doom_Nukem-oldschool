/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:44:23 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 19:59:18 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

/*
** To get 60 fps
**	if (holder->frame_time > holder->frame_delay)
**	{
**		SDL_Delay(holder->frame_time - holder->frame_delay);
**		fps = ft_strdup("60");
**	}
**	else
*/

void			draw_fps(t_wolf *holder, TTF_Font *font)
{
	char		*fps;
	char		*tmp;
	SDL_Surface	*surf;
	SDL_Texture	*texture;

	holder->frame_time = SDL_GetTicks() - holder->frame_start;
	if (holder->frame_time < holder->frame_delay)
	{
		SDL_Delay(holder->frame_delay - holder->frame_time);
		fps = ft_itoa(60);
	}
	else
		fps = ft_itoa(1000 / holder->frame_time);
	tmp = fps;
	fps = ft_strjoin("FPS: ", fps);
	free(tmp);
	surf = TTF_RenderText_Solid(font, fps, WHITE);
	free(fps);
	texture = SDL_CreateTextureFromSurface(holder->renderer, surf);
	SDL_RenderCopy(holder->renderer, texture, NULL, &(SDL_Rect){5, 5, 56, 14});
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
	draw_score(holder);
}

void			draw_text(t_wolf *holder, char *text, int x, int y)
{
	SDL_Surface	*surf;
	SDL_Texture	*texture;
	SDL_Rect	dest;

	surf = TTF_RenderText_Solid(holder->camera->font, text, WHITE);
	texture = SDL_CreateTextureFromSurface(holder->renderer, surf);
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	dest.x = x - (dest.w >> 1);
	dest.y = y;
	SDL_RenderCopy(holder->renderer, texture, NULL, &dest);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
}

unsigned int	alter_color_fixed(unsigned int color, int coefficient)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int ret;

	if (coefficient > 256)
		return (0xff000000);
	r = INT_F((color >> 16) & 0xff);
	g = INT_F((color >> 8) & 0xff);
	b = INT_F(color & 0xff);
	r = r - (FIX_MULT(r, coefficient));
	g = g - (FIX_MULT(g, coefficient));
	b = b - (FIX_MULT(b, coefficient));
	r = FIXED_I(r);
	g = FIXED_I(g);
	b = FIXED_I(b);
	ret = r;
	ret <<= 8;
	ret = ret | g;
	ret <<= 8;
	ret = ret | b;
	return (ret | 0xFF000000);
}

unsigned int	alter_color(unsigned int color, float coefficient)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	ret;

	if (coefficient > 1)
		return (0xff000000);
	r = color >> 16;
	g = color >> 8;
	b = color;
	r = r - (r * coefficient);
	g = g - (g * coefficient);
	b = b - (b * coefficient);
	ret = r;
	ret <<= 8;
	ret = ret | g;
	ret <<= 8;
	ret = ret | b;
	return (ret | 0xFF000000);
}

void			draw_floor(t_wolf *holder, t_camera *camera, \
unsigned int *buffer, unsigned int x)
{
	if (camera->side == 0 && camera->ray_dir_x > 0)
	{
		camera->wall_x_f = camera->map_x;
		camera->wall_y_f = camera->map_y + camera->wall_x;
	}
	else if (camera->side == 0 && camera->ray_dir_x < 0)
	{
		camera->wall_x_f = camera->map_x + 1.0;
		camera->wall_y_f = camera->map_y + camera->wall_x;
	}
	else if (camera->side == 1 && camera->ray_dir_y > 0)
	{
		camera->wall_x_f = camera->map_x + camera->wall_x;
		camera->wall_y_f = camera->map_y;
	}
	else
	{
		camera->wall_x_f = camera->map_x + camera->wall_x;
		camera->wall_y_f = camera->map_y + 1.0;
	}
	if (camera->draw_end < 0)
		camera->draw_end = holder->height;
	draw_floor1(holder, buffer, x);
	if (holder->ceiling)
		draw_floor2(holder, buffer, x);
}
