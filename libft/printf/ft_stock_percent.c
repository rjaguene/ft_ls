/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:15:13 by rojaguen          #+#    #+#             */
/*   Updated: 2018/08/10 15:36:25 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		strcat_percent(char *str, t_print res)
{
	int		i;

	i = 0;
	while (i < res.c_bool.width)
	{
		if (res.length == BUFF_SIZE - 1)
			res = ft_clean(res);
		res.buf[res.length] = str[i];
		i++;
		res.length++;
	}
	return (res);
}

char		*width_percent(char *copy, char c, int w)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < w)
		copy[i++] = c;
	return (copy);
}

t_print		stock_percent(t_print res)
{
	char	*str;

	if (res.c_bool.width > 0)
	{
		str = ft_memalloc(res.c_bool.width);
		if (res.c_bool.zero == 1 && res.c_bool.neg == 0)
			str = width_percent(str, '0', res.c_bool.width);
		else
			str = width_percent(str, ' ', res.c_bool.width);
		if (res.c_bool.neg == 0)
			str[res.c_bool.width - 1] = '%';
		if (res.c_bool.neg == 1)
			str[0] = '%';
		res = strcat_percent(str, res);
		ft_strdel(&str);
	}
	else
		res = (ft_strcat_f(0, res, '%'));
	return (res);
}
