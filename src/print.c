/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:30:28 by rojaguen          #+#    #+#             */
/*   Updated: 2018/11/07 15:49:34 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     get_max(t_file *lst)
{
    int i;
    int a;

    a = 0;
    while (lst)
    {
        i = ft_strlen(lst->name);
            if (i > a)
                a = i;
        lst = lst->next;
    }
    return (a + 1);
}

void    basic(t_file *lst)
{
    int max;
    int size;
    
    max = get_max(lst);
    while (lst)
    {
        ft_printf("%s", lst->name);
        size = ft_strlen(lst->name);
        if (lst->next)
            while (size++ < max)
                ft_putchar(' ');
        lst = lst->next;
    }
    ft_putchar('\n');
}

void    print(t_file *lst)
{
    basic(lst);

}
