/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:19:19 by rojaguen          #+#    #+#             */
/*   Updated: 2018/08/10 15:35:26 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_nb_digit(unsigned long n)
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

char			*ft_itoa_cast_lu(uintmax_t n, char *p, int *a, t_print res)
{
	char	*s;
	int		i;

	i = ft_nb_digit(n);
	if ((s = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[i--] = '\0';
	if (n == 0)
		s[i] = 48;
	while (n > 0)
	{
		s[i--] = n % 10 + 48;
		n = n / 10;
	}
	i = 0;
	if ((res.c_bool.width > (int)ft_strlen(s)))
		*a = res.c_bool.width - *a - 3 + (res.c_bool.width - ft_strlen(s));
	else
		*a = 0;
	while (s[i])
		p[(*a)++] = s[i++];
	ft_strclr(s);
	return (NULL);
}

char			*ft_itoa_cast(unsigned long n, char *p, int *a, t_print res)
{
	char	*s;
	int		i;

	i = ft_nb_digit(n);
	if ((s = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[i--] = '\0';
	while (n > 0)
	{
		s[i--] = n % 10 + 48;
		n = n / 10;
	}
	i = -1;
	if ((res.c_bool.width > (int)ft_strlen(s)))
		*a = res.c_bool.width - *a - 3 + (res.c_bool.width - ft_strlen(s));
	else
		*a = 0;
	while (s[++i])
		p[(*a)++] = s[i];
	ft_strclr(s);
	return (NULL);
}
