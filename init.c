/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:39:00 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 14:34:06 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#define ARGB SDL_PIXELFORMAT_ARGB8888

void	ft_skybox_init(t_camera *camera, t_wolf *holder)
{
	camera->skybox_tex[0] = load_tex(RENDER, "./resourses/skybox_up.png");
	camera->skybox_tex[1] = load_tex(RENDER, "./resourses/skybox_bottom.png");
	camera->skybox_tex[2] = load_tex(RENDER, "./resourses/skybox_test1.jpg");
	camera->skybox_tex[3] = load_tex(RENDER, "./resourses/skybox_test3.jpg");
}

void	ft_camera_init_2(t_camera *camera)
{
	camera->texture[0] = load_image("./texture/fence_wire2.png");
	camera->texture[1] = load_image("./texture/portal.png");
	camera->texture[2] = load_image("./texture/wall_wire_blue.png");
	camera->texture[3] = load_image("./texture/brick_lblue1.png");
	camera->texture[4] = load_image("./texture/floor_wire_violet.png");
	camera->texture[5] = load_image("./texture/light_on.png");
	camera->texture[6] = load_image("./texture/fury_poster.png");
	camera->texture[7] = load_image("./texture/brick_pink2.png");
	camera->texture[8] = load_image("./texture/wall_texture11.png");
	camera->texture[9] = load_image("./texture/light_on.png");
	camera->texture[10] = load_image("./texture/light_off.png");
	camera->texture[11] = load_image("./texture/chess.png");
	camera->texture[12] = load_image("./texture/tron.png");
	camera->texture[13] = load_image("./texture/fence_wire2_dmg.png");
	camera->texture[14] = load_image("./texture/portal_dmg.png");
	camera->texture[15] = load_image("./texture/wall_wire_blue_dmg.png");
	camera->texture[16] = load_image("./texture/brick_lblue1_dmg.png");
	camera->texture[17] = load_image("./texture/floor_wire_violet_dmg.png");
	camera->texture[18] = load_image("./texture/light_on_dmg.png");
	camera->texture[19] = load_image("./texture/fury_poster_dmg.png");
	camera->texture[20] = load_image("./texture/brick_pink2_dmg.png");
	camera->texture[21] = load_image("./texture/wall_texture11_dmg.png");
	camera->texture[22] = load_image("./texture/light_on_dmg.png");
	camera->texture[23] = load_image("./texture/light_off_dmg.png");
	camera->sound[8] = load_chunk("./resourses/speed.wav");
}

void	ft_camera_init(t_camera *camera, t_wolf *holder)
{
	camera->dir_x = -1;
	camera->dir_y = 0;
	camera->plane_x = 0;
	camera->plane_y = 0.66;
	camera->camera_x = 0;
	camera->camera_y = 0;
	camera->ray_dir_x = 0;
	camera->ray_dir_y = 0;
	camera->map_x = 0;
	camera->map_y = 0;
	camera->is_hit = 0;
	camera->move_speed = 0.08;
	camera->rot_speed = -0.06;
	if (!(camera->font = TTF_OpenFont("./resourses/font.ttf", 20)))
		ft_print_error("Unable to load font");
	ft_camera_init_2(camera);
	camera->sound[0] = load_chunk("./resourses/dstelept.wav");
	camera->sound[1] = load_chunk("./resourses/death.wav");
	camera->sound[2] = load_chunk("./resourses/pickup.wav");
	camera->sound[3] = load_chunk("./resourses/jump.wav");
	camera->sound[4] = load_chunk("./resourses/levelup.wav");
	camera->sound[5] = load_chunk("./resourses/light_on.wav");
	camera->sound[6] = load_chunk("./resourses/light_off.wav");
	camera->sound[7] = load_chunk("./resourses/weapon_pick.wav");
	ft_skybox_init(camera, holder);
}

/*
**	put in the end of init_image to hide coursor
**	SDL_SetRelativeMouseMode(SDL_TRUE);
*/

void	ft_init_image(t_wolf *holder)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		ft_print_error("Failed to init SDL");
	if ((holder->window = SDL_CreateWindow("Woo!", SDL_WINDOWPOS_CENTERED, \
	SDL_WINDOWPOS_CENTERED, holder->width, holder->height, 0)) < 0)
		ft_print_error("Failed to create window. Exiting");
	SDL_GetWindowSize(holder->window, &WIDTH, &HEIGHT);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_print_error("Unable to load png");
	if ((TTF_Init()))
		ft_print_error("Unable to init ttf");
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_print_error("Unable to init audio!");
	holder->music = load_music("./resourses/soundtrack.mp3");
	if (!(holder->renderer = SDL_CreateRenderer(holder->window, -1, \
		SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_ACCELERATED)))
		ft_print_error("Unable to create renderer");
	if ((SDL_SetRenderDrawBlendMode(holder->renderer, SDL_BLENDMODE_BLEND)))
		ft_print_error("Unable to set renderer blend mode");
	if (SDL_SetRenderDrawColor(holder->renderer, 0, 0, 0, 0))
		ft_print_error("SDL_SetRenderDrawColor failed");
	if (!(holder->screen = SDL_CreateTexture(holder->renderer,
		ARGB, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT)))
		ft_print_error("Screen texture not created!");
	SDL_SetTextureBlendMode(holder->screen, SDL_BLENDMODE_BLEND);
}
