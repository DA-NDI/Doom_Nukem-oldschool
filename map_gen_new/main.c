/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:35:47 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 17:48:31 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"


void			list_remove(t_line **list, t_line *node)
{
	t_line *tmp;

	if (list == NULL || *list == NULL || node == NULL)
		return ;
	if (*list == node)
	{
		ft_putstr("removed\n");
		*list = (*list)->next;
		free(node);
		node = NULL;
	}
	else
	{
		tmp = *list;
		while (tmp->next && tmp->next != node)
			tmp = tmp->next;
		if (tmp->next)
		{
			tmp->next = node->next;
			free(node);
			node = NULL;
		}
	}
}

void			list_destroy(t_line **list)
{
	if (list == NULL)
		return ;
	while (*list != NULL)
	{
		list_remove(list, *list);
	}
}

void			itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (strdup("-2147483648"));
	tmpn = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char			*concat(char *s1, char *s2)
{
	char *result;

	result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return (result);
}

void			set_rect_for_texture(t_global *global)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 1375;
	y = 250;
	while (i < 16)
	{
		if (i == 4 || i == 8 || i == 12)
		{
			y += 100;
			x = 1375;
		}
		global->texture_rect[i].x = x;
		global->texture_rect[i].y = y;
		global->texture_rect[i].w = 75;
		global->texture_rect[i].h = 75;
		if (i < 16)
			SDL_RenderCopy(global->renderer,
		global->texture[i], NULL, &global->texture_rect[i]);
		x += 100;
		i++;
	}
}

t_line			*create(t_global global)
{
	t_line *q;

	q = malloc(sizeof(t_line));
	q->x1 = global.x1;
	q->y1 = global.y1;
	q->x2 = global.x2;
	q->y2 = global.y2;
	q->texture_number = global.current_texture;
	q->next = NULL;
	return (q);
}

void			push(t_line **head, t_global global)
{
	t_line *new;

	new = create(global);
	new->next = *head;
	*head = new;
}

SDL_Rect		*create_rect(int x, int y, int w, int h)
{
	SDL_Rect *new;

	new = (SDL_Rect*)(malloc(sizeof(SDL_Rect)));
	new->x = x;
	new->y = y;
	new->w = w;
	new->h = h;
	return (new);
}

void			put_text(char *s, int ys, t_global global, int xs)
{
	int				x;
	int				y;
	SDL_Color		color;
	SDL_Surface		*surface;
	SDL_Rect		*link;

	x = 30;
	y = 30;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	surface = TTF_RenderText_Solid(global.font, s, color);
	global.textur = SDL_CreateTextureFromSurface(global.renderer, surface);
	SDL_QueryTexture(global.textur, NULL, NULL, &x, &y);
	link = create_rect(xs, ys, x, y);
	SDL_RenderCopy(global.renderer, global.textur, NULL, link);
	free(link);
	SDL_FreeSurface(surface);
}

int				in_save_to_file(int x, int y)
{
	if (x > 1375 && y > 775 && x <= 1750 && y <= 875)
		return (1);
	else
		return (0);
}

int				dot_in_tex(int x, int y, t_global global, t_tools ij)
{
	if ((x > (ij.y * global.ymode)) && (y > (ij.x * global.xmode))
		&& (x < (ij.y * global.ymode + global.ymode)) && y <
		(ij.x * global.xmode + global.xmode))
	{
		return (1);
	}
	return (0);
}

int				chech_for_dot(t_line *cur, t_tools ij, t_global *global)
{
	float	t;
	int		x;
	int		y;

	while (cur)
	{
		t = 0;
		while (t < 1)
		{
			x = cur->x1 * (1. - t) + cur->x2 * t;
			y = cur->y1 * (1. - t) + cur->y2 * t;
			if (dot_in_tex(x, y, *global, ij) == 1)
				return (cur->texture_number);
			t += .01;
		}
		cur = cur->next;
	}
	return (-1);
}

void			push_tex_map(t_line **lines, t_global *global)
{
	t_line	*cur;
	int		g;
	t_tools	ij;

	ij.x = 0;
	cur = *lines;
	g = 0;
	while (++ij.x <= global->mode)
	{
		ij.y = 0;
		while (++ij.y <= global->mode)
		{
			cur = *lines;
			if ((g = chech_for_dot(cur, ij, global)) >= 0)
				ft_putnbr_fd(g, global->fd);
			else
				ft_putstr_fd(" ", global->fd);
		}
		ft_putstr_fd("\n", global->fd);
	}
}

int				number_of_lines(t_line *cur)
{
	int		i;

	i = 0;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

void			add_head(t_global *global, t_line *cur)
{
	ft_putnbr_fd(cur->texture_number, global->fd);
	ft_putstr_fd(" ", global->fd);
	ft_putnbr_fd(cur->x1, global->fd);
	ft_putstr_fd(" ", global->fd);
	ft_putnbr_fd(cur->y1, global->fd);
	ft_putstr_fd(" ", global->fd);
	ft_putnbr_fd(cur->x2, global->fd);
	ft_putstr_fd(" ", global->fd);
	ft_putnbr_fd(cur->y2, global->fd);
	ft_putstr_fd(" ", global->fd);
	if (abs(cur->height) > 300)
		ft_putnbr_fd(300, global->fd);
	else
		ft_putnbr_fd(abs(cur->height), global->fd);
	ft_putstr_fd("\n", global->fd);
}

void			push_cord(t_global *global)
{
	int i;
	int j;

	i = -1;
	while (++i < global->mode)
	{
		j = -1;
		while (++j < global->mode)
		{
			if ((i == 0 || i == global->mode - 1))
				ft_putstr_fd("1", global->fd);
			else if ((j == 0 || j == global->mode - 1))
				ft_putstr_fd("1", global->fd);
			else if ((global->map[j][i]) >> 16 <= 0 || (global->map[j][i]
			>> 16) > 16)
				ft_putstr_fd("0", global->fd);
			else
				ft_putchar_fd((char)(global->map[j][i] >> 16) + '0',
				global->fd);
		}
		ft_putstr_fd("\n", global->fd);
	}
}

void			push_height(t_global *global)
{
	int i;
	int j;

	i = -1;
	ft_putstr_fd("Height map:\n", global->fd);
	while (++i < global->mode)
	{
		j = -1;
		while (++j < global->mode)
		{
			ft_putstr_fd("0", global->fd);
			ft_putstr_fd(" ", global->fd);
		}
		ft_putstr_fd("\n", global->fd);
	}
}

void			make_exit(t_line **lines, t_global *global)
{
	t_line	*cur;

	cur = *lines;
	if (cur)
	{
		ft_putnbr_fd(number_of_lines(cur), global->fd);
		ft_putstr_fd(" ", global->fd);
		ft_putnbr_fd(global->mode, global->fd);
		ft_putstr_fd("\n", global->fd);
	}
	while (cur)
	{
		add_head(global, cur);
		cur = cur->next;
	}
	ft_putstr_fd("\n", global->fd);
	push_cord(global);
	ft_putstr_fd("\n", global->fd);
	push_height(global);
}

void			draw_lines_rect(t_global global)
{
	SDL_Rect *link;

	link = create_rect(100, 100, 1200, 800);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
	link = create_rect(1375, 125, 375, 100);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
	link = create_rect(1375, 775, 375, 100);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
	link = create_rect(1375, 650, 375, 100);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
	link = create_rect(1350, 100, 425, 800);
	SDL_RenderDrawRect(global.renderer, link);
	free(link);
}

void			dot_in_texture(int x, int y, t_global *global, t_line *cur)
{
	SDL_Rect	*link;
	t_tools		xy;

	xy.x = 100;
	while (xy.x < 1300)
	{
		xy.y = 100;
		while (xy.y < 900)
		{
			if (x > xy.x && y > xy.y
				&& x < xy.x + global->xmode && y < xy.y + global->ymode)
			{
				link = create_rect(xy.x, xy.y, global->xmode, global->ymode);
				SDL_RenderCopy(global->renderer,
			global->texture[cur->texture_number], NULL, link);
				global->map[(xy.x - 100) / global->xmode][(xy.y - 100) /
				global->ymode] = ((((unsigned int)(cur->texture_number + 1))
				<< 16) |
				(unsigned int)(cur->height));
				free(link);
			}
			xy.y += global->ymode;
		}
		xy.x += global->xmode;
	}
}

void			draw_lines(t_global global)
{
	t_line	*cur;
	int		x;
	int		y;
	float	t;

	cur = global.lines;
	while (cur)
	{
		t = 0;
		while (t < 1)
		{
			x = cur->x1 * (1. - t) + cur->x2 * t;
			y = cur->y1 * (1. - t) + cur->y2 * t;
			dot_in_texture(x, y, &global, cur);
			t += .01;
		}
		cur = cur->next;
	}
}

int				in_texture(int x, int y)
{
	int i;
	int x1;
	int y1;

	i = 0;
	x1 = 1375;
	y1 = 250;
	while (i < 16)
	{
		if (i == 4 || i == 8 || i == 12 || i == 16)
		{
			y1 += 100;
			x1 = 1375;
		}
		if (x > x1 && y > y1 && x <= x1 + 75 && y <= y1 + 75)
			return (i);
		i++;
		x1 += 100;
	}
	return (-1);
}

int				dot_in_map(int x1, int y1)
{
	if (x1 > MAP_REC_X && y1 > MAP_REC_Y
		&& x1 < MAP_REC_W && y1 < MAP_REC_H)
		return (0);
	else
		return (1);
}

void			add_texture2(t_global *global, int i)
{
	char *tmp;
	char *tmp1;
	char *n;

	while (i < 16)
	{
		n = ft_itoa(i);
		tmp = ft_strjoin("texture/texture", n);
		tmp1 = ft_strjoin(tmp, ".png");
		global->texture[i] = IMG_LoadTexture(global->renderer, tmp1);
		free(tmp);
		free(tmp1);
		free(n);
		if (global->texture[i] == NULL)
		{
			fprintf(stderr, "Texture error png");
			exit(1);
		}
		i++;
	}
}

void			add_texture(t_global *global)
{
	int		i;
	char	*tmp;
	char	*tmp1;
	char	*n;

	i = -1;
	global->pos = 0;
	global->x1 = 0;
	global->y1 = 0;
	while (++i < 8)
	{
		n = ft_itoa(i);
		tmp = ft_strjoin("texture/texture", n);
		tmp1 = ft_strjoin(tmp, ".jpg");
		global->texture[i] = IMG_LoadTexture(global->renderer, tmp1);
		free(tmp);
		free(tmp1);
		free(n);
		if (global->texture[i] == NULL)
		{
			fprintf(stderr, "Texture error");
			exit(1);
		}
	}
	add_texture2(global, i);
}

void			init_sdl(t_global *global)
{
	t_tools ij;

	ij.x = -1;
	bzero(global->text, 9);
	global->map = (unsigned int**)malloc(global->mode * sizeof(unsigned int*));
	while (++ij.x < global->mode)
	{
		global->map[ij.x] = (unsigned int*)malloc(global->mode
		* sizeof(unsigned int));
		ij.y = -1;
		while (++ij.y < global->mode)
			global->map[ij.x][ij.y] = 0;
	}
	global->window = SDL_CreateWindow("MAP",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	global->renderer = SDL_CreateRenderer(global->window,
		-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	global->x2 = 110;
	global->y2 = 110;
	global->drawing = 0;
	TTF_Init();
	global->font = TTF_OpenFont("font.ttf", 50);
	add_texture(global);
	global->done = SDL_FALSE;
}

void			pos_0_pick_tex(t_global *global)
{
	if (global->event.type == SDL_KEYUP)
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"E") == 0)
			global->pos = 3;
	if (global->event.type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_GetMouseState(&global->x1, &global->y1);
		if ((global->current_texture = in_texture(global->x1, global->y1)) >= 0)
		{
			global->pos = 1;
		}
		if (in_save_to_file(global->x1, global->y1) > 0)
		{
			SDL_LogMessage(SDL_LOG_CATEGORY_TEST,
				SDL_LOG_PRIORITY_DEBUG, "exit");
			make_exit(&global->lines, global);
			global->done = SDL_TRUE;
		}
	}
}

void			pos_1_set_dot(t_global *global)
{
	if (global->event.type == SDL_MOUSEBUTTONDOWN &&
	(SDL_GetMouseState(&global->x1, &global->y1) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		if ((dot_in_map(global->x1, global->y1)) ||
		(dot_in_map(global->x2, global->y2)))
			return ;
		if (!global->drawing)
		{
			global->x2 = global->x1;
			global->y2 = global->y1;
			global->drawing = 1;
		}
		else
		{
			if (global->z)
				push(&global->lines, *global);
			else
			{
				global->lines = create(*global);
				global->z = 1;
			}
			global->pos = 2;
			global->drawing = 0;
		}
	}
}

void			global_pos_2_write(t_global *global)
{
	if (global->event.type == SDL_KEYUP)
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"Backspace") == 0)
			global->text[strlen(global->text) - 1] = '\0';
	if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
	"Return") == 0)
	{
		if ((global->lines->height = abs(atoi(global->text))) > 300)
			global->lines->height = 300;
		if (global->pos != 6)
			global->lines->texture_number = global->current_texture;
		bzero(global->text, strlen(global->text));
		global->pos = 0;
	}
}

int				find_closest_wall(t_global *global)
{
	t_line *cur;

	cur = global->lines;
	while (cur)
	{
		if (((cur->x1 - 100) / global->xmode) == ((global->x1 - 100) /
		global->xmode) &&
			((cur->y1 - 100) / global->ymode) == ((global->y1 - 100) /
			global->ymode))
		{
			global->to_edit = cur;
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

void			push_to_front(t_line **head, t_line *global)
{
	t_line *q;

	q = malloc(sizeof(t_line));
	q->x1 = global->x1;
	q->y1 = global->y1;
	q->x2 = global->x2;
	q->y2 = global->y2;
	q->height = global->height;
	q->texture_number = global->texture_number;
	q->next = *head;
	*head = q;
}

void			global_pos_3_edit(t_global *global)
{
	if (global->event.type == SDL_MOUSEBUTTONDOWN &&
	(SDL_GetMouseState(&global->x1, &global->y1) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		if (dot_in_map(global->x1, global->y1))
			return ;
		if (find_closest_wall(global))
		{
			global->pos = 4;
			push_to_front(&global->lines, global->to_edit);
			list_remove(&global->lines, global->to_edit);
		}
	}
}

void			draw_grid(t_global global)
{
	int x;
	int y;

	x = 100;
	y = 100;
	while (x < 1300)
	{
		y = 100;
		while (y < 900)
		{
			SDL_RenderDrawLine(global.renderer, x, y, x + global.xmode, y);
			SDL_RenderDrawLine(global.renderer, x, y, x, y + global.ymode);
			y += global.ymode;
		}
		x += global.xmode;
	}
}

void			redraw(t_global *global)
{
	SDL_SetRenderDrawColor(global->renderer, 0, 0, 0, 255);
	SDL_RenderClear(global->renderer);
	if (global->pos == 0 || global->pos == 5)
		put_text("Pick Texture", 165, *global, 1450);
	else if (global->pos == 1)
		put_text("Pick 2 Dots", 165, *global, 1450);
	else if (global->pos == 2 || global->pos == 6)
	{
		put_text("Set Height", 165, *global, 1450);
		put_text(global->text, 685, *global, 1400);
	}
	else if (global->pos == 3)
		put_text("Pick wall", 165, *global, 1450);
	else if (global->pos == 4)
		put_text("EDIT: D, T, H", 165, *global, 1450);
	put_text("Save to file", 805, *global, 1450);
	set_rect_for_texture(global);
	SDL_SetRenderDrawColor(global->renderer, 255, 255, 255, 0);
	draw_grid(*global);
	draw_lines(*global);
	draw_lines_rect(*global);
	SDL_RenderPresent(global->renderer);
}

void			chech_for_d_t_h(t_global *global)
{
	if (global->event.type == SDL_KEYUP)
	{
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"D") == 0)
		{
			list_remove(&global->lines, global->lines);
			global->pos = 0;
		}
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"T") == 0)
			global->pos = 5;
		if (strcmp(SDL_GetKeyName(global->event.key.keysym.sym),
		"H") == 0)
			global->pos = 6;
	}
}

void			global_pos_0(t_global *global)
{
	pos_0_pick_tex(global);
}

void			global_pos_1(t_global *global)
{
	pos_1_set_dot(global);
}

void			global_pos_2(t_global *global)
{
	if (global->event.type == SDL_TEXTINPUT)
		strcat(global->text, global->event.text.text);
}

void			global_pos_26(t_global *global)
{
	global_pos_2_write(global);
}

void			global_pos_3(t_global *global)
{
	global_pos_3_edit(global);
}

void			global_pos_5(t_global *global)
{
	global->current_texture = -1;
	pos_0_pick_tex(global);
	if (global->current_texture >= 0)
	{
		global->lines->texture_number = global->current_texture;
		global->pos = 0;
	}
}

void			event(t_global *global)
{
	if (global->event.type == SDL_QUIT)
		global->done = SDL_TRUE;
	if (global->pos == 0)
		global_pos_0(global);
	else if (global->pos == 1)
		global_pos_1(global);
	else if ((global->pos == 2 || global->pos == 6) &&
	strlen(global->text) <= 2)
		global_pos_2(global);
	if (global->pos == 2 || global->pos == 6)
		global_pos_26(global);
	if (global->pos == 3)
		global_pos_3(global);
	if (global->pos == 4)
	{
		chech_for_d_t_h(global);
		redraw(global);
	}
	if (global->pos == 5)
		global_pos_5(global);
	redraw(global);	
}

void			loop(t_global global)
{
	while (!global.done)
	{
		while (SDL_PollEvent(&global.event))
			event(&global);
	}
}

int				words_len(char **cords)
{
	int i;

	i = 0;
	while (*cords)
	{
		cords++;
		i++;
	}
	return (i);
}

void			free_words(char **words)
{
	int i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	words = NULL;
}

void			create_file(char *s, t_global *global)
{
	if (!*s)
		exit(0);
	global->fd = open(s, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (!global->fd)
		exit(0);
}

void			chech_lines(t_global *global, int lines)
{
	char	*line;
	char	**cords;
	t_line	wall;

	while (lines--)
	{
		if (!ft_get_next_line(global->fd, &line))
			exit(0);
		cords = ft_strsplit(line, ' ');
		if (words_len(cords) != 6)
			exit(0);
		if ((wall.texture_number = (abs(ft_atoi(cords[0])))) >= 16)
			exit(0);
		wall.x1 = abs(ft_atoi(cords[1]));
		wall.y1 = abs(ft_atoi(cords[2]));
		wall.x2 = abs(ft_atoi(cords[3]));
		wall.y2 = abs(ft_atoi(cords[4]));
		wall.height = abs(ft_atoi(cords[5]));
		if (wall.height > 300)
			exit(0);
		push_to_front(&global->lines, &wall);
		free_words(cords);
		free(line);
	}
}

void			edit_file(char *s, t_global *global)
{
	char *line;
	char **cords;

	line = NULL;
	cords = NULL;
	if (!*s)
		exit(0);
	if ((global->fd = open(s, O_RDONLY)) <= 0)
		exit(0);	
	if (!(ft_get_next_line(global->fd, &line)))
		exit(0);
	cords = ft_strsplit(line, ' ');
	if (words_len(cords) != 2)
		exit(0);
	if ((ft_atoi(cords[1]) != global->mode))
		exit(0);
	if (ft_atoi(cords[0]) >= 1)
		global->z = 1;
	free(line);
	chech_lines(global, ft_atoi(cords[0]));
	free_words(cords);
	close(global->fd);
	create_file(s, global);
}

void			set_global_mode(t_global *global)
{
	if (global->mode == 10)
	{
		global->xmode = 120;
		global->ymode = 80;
	}
	else
	{
		global->xmode = 24;
		global->ymode = 16;
	}
}

void			ac_4(t_global *global, char **av)
{
	global->z = 0;
	if (ft_atoi(av[1]) == 10 || ft_atoi(av[1]) == 50)
		global->mode = ft_atoi(av[1]);
	else
		exit(0);
	if (ft_strcmp(av[2], "-n") == 0)
		create_file(av[3], global);
	else if (ft_strcmp(av[2], "-e") == 0)
		edit_file(av[3], global);
	else
		exit(0);
}

int				main(int ac, char **av)
{
	t_global global;

	if (ac == 4)
		ac_4(&global, av);
	else
	{
		ft_putstr("Usage: ./map [grid size] [-n || -e] [filename]\n");
		return (0);
	}
	set_global_mode(&global);
	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		init_sdl(&global);
		loop(global);
		if (global.renderer)
			SDL_DestroyRenderer(global.renderer);
		if (global.window)
			SDL_DestroyWindow(global.window);
	}
	TTF_Quit();
	SDL_Quit();
	system("leaks map");
	return (0);
}
