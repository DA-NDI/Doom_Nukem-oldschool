/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:00:28 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/20 20:35:34 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_del(char *dest, char *src)
{
	char	*s;

	s = ft_strjoin(dest, src);
	ft_strdel(&src);
	return (s);
}
