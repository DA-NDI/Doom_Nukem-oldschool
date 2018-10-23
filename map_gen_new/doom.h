/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:03:36 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/22 16:16:39 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define WIN_X 1900
# define WIN_Y 1000
# define BAR_X 1400
# define BAR_Y 100
# define BAR_W 400
# define BAR_H 800
# define MAP_REC_X 100
# define MAP_REC_Y 100
# define MAP_REC_W 1300
# define MAP_REC_H 900

typedef struct		s_tools
{
	int				x;
	int				y;
}					t_tools;

typedef	struct		s_rect
{
	int				x;
	int				y;
	int				w;
	int				h;
}					t_rect;

typedef	struct		s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	unsigned int	texture_number;
	int				height;
	struct s_line	*next;
}					t_line;

typedef	struct		s_global
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				pos;
	int				current_texture;
	SDL_Texture		*texture[16];
	SDL_Texture		*textur;
	SDL_Rect		texture_rect[18];
	TTF_Font		*font;
	SDL_bool		done;
	SDL_Event		event;
	char			text[9];
	int				z;
	int				drawing;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	t_line			*lines;

	t_line			*to_edit;
	unsigned int	**map;
	int				fd;
	int				mode;
	int				xmode;
	int				ymode;
}					t_global;

#endif
