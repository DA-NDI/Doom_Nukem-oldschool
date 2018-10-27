/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suzumia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:25:31 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/27 16:14:28 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			create_file(char *s, t_global *global)
{
	char *w;

	if (!*s)
		exit(0);
	system("tar -xzf ../package -C ../");
	w = ft_strjoin("../maps/", s);
	global->fd = open(w, O_RDWR | O_CREAT | O_TRUNC, 0666);
	free(w);
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
		if (get_next_line(global->fd, &line) <= 0)
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
	system("tar -xzf ../package -C ../");
	if (!*s)
		exit(0);
	if ((global->fd = open(s, O_RDONLY)) <= 0)
		exit(0);
	if (get_next_line(global->fd, &line) <= 0)
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
