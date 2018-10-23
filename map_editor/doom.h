/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:03:36 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:46:59 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include <get_next_line.h>
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

void				if_it(t_global *global, int *q);
void				list_remove(t_line **list, t_line *node);
void				list_destroy(t_line **list);
void				itoa_isnegative(int *n, int *negative);
char				*ft_itoa(int n);
char				*concat(char *s1, char *s2);
void				set_rect_for_texture(t_global *global);
t_line				*create(t_global global);
void				push(t_line **head, t_global global);
SDL_Rect			*create_rect(int x, int y, int w, int h);
void				put_text(char *s, int ys, t_global global, int xs);
int					in_save_to_file(int x, int y);
int					dot_in_tex(int x, int y, t_global global, t_tools ij);
int					chech_for_dot(t_line *cur, t_tools ij, t_global *global);
void				push_tex_map(t_line **lines, t_global *global);
int					number_of_lines(t_line *cur);
void				add_head(t_global *global, t_line *cur);
void				push_fig(t_global *global, int i, int j);
void				push_cord(t_global *global);
void				push_height(t_global *global);
void				make_exit(t_line **lines, t_global *global);
void				draw_lines1_rect(t_global global);
void				dot_in_texture(int x, int y, t_global *global, t_line *cur);
void				draw_lines1(t_global global);
int					in_texture(int x, int y);
int					dot_in_map(int x1, int y1);
void				add_texture2(t_global *global);
void				add_texture(t_global *global);
void				init_sdl(t_global *global);
void				pos_0_pick_tex(t_global *global);
void				pos_1_set_dot(t_global *global);
void				global_pos_2_write(t_global *global);
int					find_closest_wall(t_global *global);
void				push_to_front(t_line **head, t_line *global);
void				global_pos_3_edit(t_global *global);
void				draw_grid(t_global global);
void				redraw(t_global *global);
void				chech_for_d_t_h(t_global *global);
void				global_pos_0(t_global *global);
void				global_pos_1(t_global *global);
void				global_pos_2(t_global *global);
void				global_pos_26(t_global *global);
void				global_pos_3(t_global *global);
void				global_pos_5(t_global *global);
void				event(t_global *global);
void				loop(t_global global);
int					words_len(char **cords);
void				free_words(char **words);
void				create_file(char *s, t_global *global);
void				chech_lines(t_global *global, int lines);
void				edit_file(char *s, t_global *global);
void				set_global_mode(t_global *global);
void				ac_4(t_global *global, char **av);

#endif
