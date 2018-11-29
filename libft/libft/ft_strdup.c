/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <rojaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:42:06 by rojaguen          #+#    #+#             */
/*   Updated: 2018/10/25 18:45:10 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	if ((str = (char*)malloc((ft_strlen(s1) + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

unsigned char	*ft_unsigned_dup(unsigned char *s1)
{
	int i;
	unsigned char *str;

	i = 0;
	if (!s1)
		return (NULL);
	if ((str = (unsigned char*)malloc((ft_strlen((char*)s1) + 1) * sizeof(str))) == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
