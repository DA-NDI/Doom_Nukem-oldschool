/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:00:28 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/31 22:08:01 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_del_all(char *dest, char *src)
{
	char	*s;

	s = ft_strjoin(dest, src);
	ft_strdel(&dest);
	ft_strdel(&src);
	return (s);
}
