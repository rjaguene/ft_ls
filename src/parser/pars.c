/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:58:10 by rojaguen          #+#    #+#             */
/*   Updated: 2018/10/13 17:17:34 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		pars(t_env **env, int argc, char **argv, int i)
{
	int a;

	a = 0;
//	if (argc == 1)
//		return (1);
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-t"))
			(*env)->pars.t = 1;
		else if (ft_strcmp(argv[i], "-l"))
			(*env)->pars.l = 1;
		else if (ft_strcmp(argv[i], "-R"))
			(*env)->pars.R = 1;
		else if (ft_strcmp(argv[i], "-r"))
			(*env)->pars.r = 1;
		else if (ft_strcmp(argv[i], "-a"))
			(*env)->pars.a = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

int		init(t_env **env, int argc, char **argv)
{
//	(env)->pars = malloc(sizeof(pars));
	if (!pars(env, argc, argv, 1))
		exit(ft_printf("ls: illegal option usage: ls [-lraRt] [file ...]);"));
	return (0);
}
