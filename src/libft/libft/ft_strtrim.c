/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:45:21 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/11 16:41:55 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	char	*copy_s;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && *s)
		i++;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && *s)
		len--;
	if (len < i)
		len = i - 1;
	if (!(copy_s = (char*)malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	if (len <= 0)
		len = 1;
	while (i <= len)
		copy_s[j++] = s[i++];
	copy_s[j] = '\0';
	return (copy_s);
}
