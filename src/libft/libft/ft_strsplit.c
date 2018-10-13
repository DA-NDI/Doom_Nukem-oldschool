/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:23:41 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/12 16:55:55 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int		ft_words(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static	char	**ft_put(char const *s, char **s1, char c)
{
	unsigned int	a;
	unsigned int	b;
	int				i;

	i = 0;
	a = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			a = i;
			while (s[i] && s[i] != c)
				i++;
			s1[b] = ft_strsub(s, a, i - a);
			b++;
			s1[b] = NULL;
		}
	}
	s1[b] = 0;
	return (s1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_words(s, c);
	if (!s)
		return (NULL);
	if (!(result = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	ft_bzero(result, words + 1);
	return (ft_put(s, result, c));
}
