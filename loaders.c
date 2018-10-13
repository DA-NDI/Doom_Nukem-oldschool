/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:41:52 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/19 15:37:40 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

SDL_Texture	*load_tex(SDL_Renderer *renderer, char *path)
{
	SDL_Surface *loaded_im;
	SDL_Texture *texture;

	loaded_im = NULL;
	texture = NULL;
	loaded_im = IMG_Load(path);
	if (loaded_im != NULL)
	{
		texture = SDL_CreateTextureFromSurface(renderer, loaded_im);
		SDL_FreeSurface(loaded_im);
	}
	else
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, \
		"load_tex error", "Unable to load texture", NULL);
		ft_print_error("Unable to load texture");
	}
	return (texture);
}

void		apply_texture(int x, int y, SDL_Texture *tex, SDL_Renderer *rend)
{
	SDL_Rect pos;

	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, tex, NULL, &pos);
}

SDL_Surface	*load_image(char *path)
{
	SDL_Surface	*texture;

	texture = IMG_Load(path);
	if (texture == NULL)
		ft_print_error("Unable to load texture image!");
	return (texture);
}

Mix_Music	*load_music(char *path)
{
	Mix_Music *music;

	if (!(music = Mix_LoadMUS(path)))
		ft_print_error("Unabde to load music!");
	return (music);
}

Mix_Chunk	*load_chunk(char *path)
{
	Mix_Chunk *chunk;

	if (!(chunk = Mix_LoadWAV(path)))
		ft_print_error("Failed to load sound effect!");
	return (chunk);
}
