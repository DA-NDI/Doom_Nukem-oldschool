/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:10:04 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/12 22:38:02 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int						i;
	int						minus;
	unsigned long long		result;

	minus = 1;
	i = 0;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	if (str[i] == '+' && minus > 0)
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + str[i++] - '0';
	if (i > 20 || result >= 9223372036854775808ULL)
		return (minus == 1 ? -1 : 0);
	return (result * minus);
}
