/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:30:28 by rojaguen          #+#    #+#             */
/*   Updated: 2018/11/07 15:49:34 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int		get_inf(t_env **env, t_file **lst)
{
	DIR		*dir;
	struct	dirent *sd;
	t_file *new;

	dir = opendir(".");
	readdir(dir); //temp
	readdir(dir);
	while ((sd = readdir(dir)) != NULL)
	{
//		printf("->%s\n",sd->DT_REG);
		new = new_node();
		*lst = add_link(*lst, new);
		(*lst)->name = sd->d_name;
		(*lst)->d_type = sd->d_type;
	}
	closedir(dir);
	return (0);
}

void       cpy(t_file **a, t_file *b)
{
    (*a)->name = b->name;
    (*a)->d_type = b->d_type;
}

void swap(t_file **a, t_file **b)
{
    t_file tmp;

    tmp = **a;
    cpy(a, *b);
    cpy(b, &tmp);
}

void sort_lst(t_file **lst)
{
	t_file *a;
	t_file *b;
    
    a = *lst;
    while (a)
    {
        b = a->next;
        while (b)
        {
		    if (ft_strcmp(a->name, b->name) > 0)
                swap(&a, &b);
            b = b->next;
        }
        a = a->next;
    }
}

int		main(int argc, char **argv)
{
	t_file *lst;
//	DIR		*dir;
//	struct	dirent *sd;
	t_env	*env;

	lst = NULL;
	//if (!(env = malloc(sizeof(env))))
	//	return (0);
	//ft_bzero(&env, sizeof(env));
	get_inf(&env, &lst);
	sort_lst(&lst);
    print(lst);
	while (lst)
	{
//		ft_printf("%s\n",lst->name);
		printf("%d\n",lst->d_type);
		lst = lst->next;
	}
//	free_lst(&lst);
	exit(0);
	//init(&env, argc, argv);
//	dir = opendir(".");
/*	while ((sd = readdir(dir)) != NULL)
	{
		ft_printf("%s	",sd->d_name);
	//	if (sd->d_type)
//		ft_printf("%d\n",sd->d_ino);
	}*/
//	closedir(dir);
	return (0);
}
