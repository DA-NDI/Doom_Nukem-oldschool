/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:42:28 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/20 20:41:26 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static t_list	*ft_list_fd(t_list **buff, int fd)
{
	t_list		*temp;

	temp = *buff;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	temp->content = ft_memalloc(1);
	ft_bzero(temp->content, 1);
	temp->content_size = fd;
	temp->next = NULL;
	ft_lstadd(buff, temp);
	temp = *buff;
	return (temp);
}

static int		ft_read(t_list **buff, int fd)
{
	char	temp[BUFF_SIZE + 1];
	int		result;
	char	*free_me;

	result = 0;
	while (!(ft_strchr((*buff)->content, '\n'))
		&& (result = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[result] = '\0';
		free_me = (*buff)->content;
		(*buff)->content = ft_strjoin((char*)(*buff)->content, temp);
		ft_memdel((void**)&free_me);
	}
	return (result == -1) ? 0 : 1;
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*buff;
	char			*ptr;

	if (fd < 0 || fd > LIMIT_FD || line == NULL || BUFF_SIZE < 1)
		return (-1);
	buff = ft_list_fd(&head, fd);
	if (!(ft_read(&buff, fd)))
		return (-1);
	if (!((char*)buff->content)[0])
		return (0);
	ptr = ft_strchr(buff->content, '\n');
	if (!ptr && buff->content)
	{
		*line = ft_strdup(buff->content);
		((char*)buff->content)[0] = '\0';
		return (1);
	}
	else
		*line = ft_strsub(buff->content, 0, ptr - (char*)buff->content);
	buff->content = ft_memmove(buff->content, ptr + 1, ft_strlen(ptr));
	return (1);
}
