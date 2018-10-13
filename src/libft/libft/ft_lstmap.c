/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:10:39 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/13 13:32:34 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	f_lstdel(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		free(list->content);
		list = list->next;
		free(tmp);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*head;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (!(res = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	head = res;
	while (lst)
	{
		elem = f(lst);
		if (!(res->next = ft_lstnew(elem->content, elem->content_size)))
		{
			f_lstdel(head);
			return (NULL);
		}
		res = res->next;
		lst = lst->next;
	}
	return (head);
}
