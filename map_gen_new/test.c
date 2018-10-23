
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

	t = 0;
	while (cur)
	{
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
	ij.y = 0;
	cur = *lines;
	g = 0;
	while (++ij.x <= global->mode)
	{
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
	j = -1;
	while (++i < global->mode)
	{
		while (++j < global->mode)
		{
			if ((i == 0 || i == global->mode - 1) &&
			((global->map[j][i]) >> 16 <= 0 || (global->map[j][i] >> 16) > 7))
				ft_putstr_fd("1", global->fd);
			else if ((j == 0 || j == global->mode - 1) &&
			((global->map[j][i]) >> 16 <= 0 || (global->map[j][i] >> 16) > 7))
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
	j = -1;
	while (++i < global->mode)
	{
		while (++j < global->mode)
		{
			if ((global->map[j][i] & 0xFFFF) <= 0 ||
			(global->map[j][i] & 0xFFFF) > 300
				|| (global->map[j][i]) >> 16 >= 8)
			{
				ft_putstr_fd("0", global->fd);
				ft_putstr_fd(" ", global->fd);
			}
			else
			{
				ft_putnbr_fd(global->map[j][i] & 0xFFFF, global->fd);
				ft_putstr_fd(" ", global->fd);
			}
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
	xy.y = 100;
	while (xy.x < 1300)
	{
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

	t = 0;
	cur = global.lines;
	while (cur)
	{
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