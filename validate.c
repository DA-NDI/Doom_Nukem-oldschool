/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:36:22 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/23 23:56:25 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	tool(char *map[50], int i, int ret, char *buff)
{
	map[i] = NULL;
	check_amount(map, -1, 0);
	if (i == 0 || ret == -1)
		ft_print_error("Map is empty!");
	free(buff);
}

int		words_len(char **cords)
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

void	free_words(char **words)
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
	char	*line;
	char	**cords;
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

char	**ft_create_map(char *path, t_wolf *holder)
{
	int			fdiret[3];
	char		*buff;
	static char	*map[52];

	fdiret[1] = 0;
	if ((fdiret[0] = open(path, O_RDONLY)) < 0)
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
		map[fdiret[1]] = buff;
		fdiret[1]++;
	}
	tool(map, fdiret[1], fdiret[2], buff);
	holder->height_map = ft_create_height_map(fdiret[0]);
	return (map);
}
