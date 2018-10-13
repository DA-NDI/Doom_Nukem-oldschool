/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:49:40 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/30 17:16:27 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_handle_percent(t_field *placeholder, int *len)
{
	char	*d;

	d = ft_strdup("%");
	placeholder->plus = 0;
	placeholder->precision = 0;
	placeholder->space = 0;
	ft_put_flag(&d, placeholder);
	ft_put_width_d_i(&d, placeholder);
	ft_putstr(d);
	*len = *len + ft_strlen(d);
	free(d);
}
