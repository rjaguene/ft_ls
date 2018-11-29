/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <rojaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 06:14:41 by rojaguen          #+#    #+#             */
/*   Updated: 2017/11/27 14:52:11 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nb_digit(int n)
{
	int digit;

	digit = 0;
	if (n <= 0)
	{
		digit++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = ft_nb_digit(n);
	if ((s = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[i--] = '\0';
	if (n == 0)
		s[i] = 48;
	if (n < 0)
	{
		s[i--] = -1 * (n % 10) + 48;
		n = n / 10;
		n = n * -1;
		s[0] = '-';
	}
	while (n > 0)
	{
		s[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}
