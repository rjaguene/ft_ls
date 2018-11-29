/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 08:28:59 by rojaguen          #+#    #+#             */
/*   Updated: 2018/08/10 13:03:17 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillit(char *s_line, int fd, t_lst *data)
{
	char buf[BUFF + 1];
	char *tmp;

	ft_bzero(buf, BUFF);
	while (data->rsl && ft_strchr(buf, '\n') == 0)
	{
		ft_strclr(buf);
		if ((data->rsl = read(fd, buf, BUFF)) == -1)
			return (NULL);
		buf[data->rsl] = '\0';
		if (data->rsl == 0)
			break ;
		tmp = s_line;
		s_line = ft_strjoin(s_line, buf);
		free(tmp);
	}
	return (s_line);
}

char	*ft_get_line(char *s_line, char ***line, t_lst *data)
{
	int a;
	int i;

	a = 0;
	i = 0;
	while (s_line[i] && s_line[i] != '\n')
		i++;
	data->tmp = ft_strnew(i);
	ft_bzero(data->tmp, i);
	while (i--)
	{
		data->tmp[a] = s_line[a];
		a++;
	}
	*line[0] = ft_strdup(data->tmp);
	free(data->tmp);
	data->tmp = s_line;
	s_line = ft_strdup(s_line + a + 1);
	return (s_line);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*s_line = NULL;
	static	int		a = -1;
	t_lst			*data;

	data = malloc(sizeof(*data));
	data->rsl = 1;
	if (a != fd)
	{
		s_line = NULL;
		a = fd;
	}
	if ((s_line = ft_fillit(s_line, fd, data)) == NULL)
		return (-1);
	if (*s_line)
	{
		s_line = ft_get_line(s_line, &line, data);
		if (!(data->rsl == 0 && ft_strlen(data->tmp) == 0))
		{
			free(data->tmp);
			free(data);
			return (1);
		}
		free(data->tmp);
	}
	return (0);
}
