/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:30:28 by rojaguen          #+#    #+#             */
/*   Updated: 2018/11/07 15:49:34 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    *mempush(char *data, const void *add, int st, int sp)
{
    char *s;
    const char *cp;
    int i;

    //s = data;
    i = 1;
    cp = (char *)add;
    data[st] = '/';
    while(sp--)
    {
        data[st + i] = cp[i - 1];
        i++;
    }
    return (data);
}
