/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:36:22 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/23 23:33:37 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		check_dimensions_and_symbols(char **map, int height, int width)
{
	int		i;
	int		j;
	int		dot;

	dot = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				dot++;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '2' &&\
	map[i][j] != '\0' && map[i][j] != '3' && map[i][j] != 'P' && map[i][j]
	!= '4' && map[i][j] != '5' && map[i][j] != 'A' && map[i][j] != 'C' &&
	map[i][j] != '7' && map[i][j] != '8' && map[i][j] != '9' && map[i][j] !=
	'6' && map[i][j] != ':' && map[i][j] != ';' && map[i][j] != 'K' && map[i][j]
	!= 'H' && map[i][j] != 'S' && map[i][j] != 'B' && map[i][j] != 'G')
				return (1);
		}
		if (j != width && (map[i][0] != '\0' || map[i][j] != '\0'))
			return (1);
	}
	return (i != height || !dot) ? 1 : 0;
}

void	check_amount(char **map, int i, int j)
{
	int		cars;
	int		arcades;
	int		ammo;

	cars = 0;
	arcades = 0;
	ammo = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				cars++;
			else if (map[i][j] == 'A')
				arcades++;
			else if (map[i][j] == 'G')
				ammo++;
		}
	}
	if (cars > 3 || arcades > 5 || ammo > 4)
		ft_print_error("Too many sprites!");
}

int		check_boundaries(char **map, int height)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i][j] && map[height - 1][j])
	{
		if ((map[i][j] != '1' || map[height - 1][j]
	!= '1') && (map[i][j] != ':' || map[height - 1][j] != ':'))
			return (1);
		j++;
	}
	j = 0;
	while (++i < height)
	{
		if (map[i][j] != '1' && map[i][j] != ':')
			return (1);
		while (map[i][j++])
			;
		if (map[i][j - 2] != '1' && map[i][j - 2] != ':')
			return (1);
		j = 0;
	}
	if (map[i][j] != '\0')
		return (1);
	return (0);
}

void	ft_verify_map(char **map, t_wolf *holder)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!map || map[0][0] == '\n' || map[0][0] != '1')
		ft_print_error("Map error");
	while (map[i] != '\0')
		i++;
	while (map[0][j] != '\0')
		j++;
	holder->map_width = j - 1;
	holder->map_height = i - 2;
	if (i < 3 || j < 3)
		ft_print_error("Map is too small");
	if (j > 50)
		ft_print_error("Map is too wide");
	if (check_boundaries(map, i - 1))
		ft_print_error("Boundaries error. Should be all '1'");
	if (check_dimensions_and_symbols(map, i - 1, j))
		ft_print_error("Map dimensions or allowed symbols error");
}

void	fill_map(t_tool *tool, int *height_map[50])
{
	tool->splitted = ft_strsplit(tool->buff_height[tool->i], ' ');
	tool->a = -1;
	while (tool->splitted[++tool->a])
	{
		height_map[tool->i][tool->a] = ft_atoi(tool->splitted[tool->a]);
		height_map[tool->i][tool->a] = (height_map[tool->i][tool->a] >
		300) ? 300 : height_map[tool->i][tool->a];
		free(tool->splitted[tool->a]);
	}
	free(tool->splitted);
	free(tool->buff_height[tool->i]);
}

int		**ft_create_height_map(int fd)
{
	t_tool		tool;
	static int	*height_map[51];

	tool.i = 0;
	while (get_next_line(fd, &tool.buff) == 1)
	{
		if (ft_strlen(tool.buff) > 100 || tool.i >= 100)
		{
			free(tool.buff);
			ft_print_error("map is too big!");
		}
		tool.buff_height[tool.i++] = tool.buff;
	}

	tool.buff_height[tool.i] = NULL;
	tool.i = -1;
	write(1, "1", 1);

	while (tool.buff_height[++tool.i])
	{
		height_map[tool.i] = (int*)malloc(sizeof(int)
		* ft_strlen(tool.buff_height[tool.i]));
		fill_map(&tool, height_map);
	}
	height_map[tool.i] = NULL;

	return (height_map);
}

void	tool(char *map[50], int i, int ret, char *buff)
{
	map[i] = NULL;
	check_amount(map, -1, 0);
	if (i == 0 || ret == -1)
		ft_print_error("Map is empty!");
	free(buff);
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

void	skip_first_line(int fd)
{
	char *line;
	char **cords;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) == 1)
		cords = ft_strsplit(line, ' ');
	else
		exit(0);
	if (words_len(cords) != 2)
		exit(0);
	if ((i = ft_atoi(cords[0])) > 0)
	{
		free(line);
		while (i--)
			if (get_next_line(fd, &line) == 1)
				free(line);
	}
	else
		exit(0);
	get_next_line(fd, &line);
	free(line);
	free_words(cords);
}

char	**ft_create_map(char **argv, t_wolf *holder)
{
	int			fdiret[3];
	char		*buff;
	static char	*map[50];

	fdiret[1] = 0;
	if ((fdiret[0] = open(argv[1], O_RDONLY)) < 0)
		ft_print_error("Failed to open map file");
	skip_first_line(fdiret[0]);
	while ((fdiret[2] = get_next_line(fdiret[0], &buff)) == 1 &&
	ft_strstr(buff, "Height map:") == NULL)
	{
		if (ft_strlen(buff) > 100 || fdiret[1] >= 100)
		{
			free(buff);
			ft_print_error("map is too big!");
		}
		map[fdiret[1]] = (char*)malloc(sizeof(char) * ft_strlen(buff) + 1);
		map[fdiret[1]] = ft_strcpy(map[fdiret[1]], buff);
		free(buff);
		fdiret[1]++;
	}
	tool(map, fdiret[1], fdiret[2], buff);
	holder->height_map = ft_create_height_map(fdiret[0]);	
	return (map);
}
