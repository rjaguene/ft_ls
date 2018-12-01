/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_listing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:25:05 by rojaguen          #+#    #+#             */
/*   Updated: 2018/11/02 12:26:01 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stack    *alloc(t_stack *stack)
{
    //t_stack tmp;

    if (!stack)
    {
        stack = ft_memalloc(sizeof(*stack));
        ft_bzero(stack, sizeof(*stack));
        stack->data = ft_strnew(STACK_CAPACITY);
        stack->len = 0;
        return(stack) ;
    }
    return (stack);
    /*stack->capacity += STACK_CAPACITY;
    tmp = stack->(data);
    ft_memalloc(stack->data, capacity)
    ft_memcpy(stack->data, tmp);*/
}

void    *new_path(void *add)
{
    static t_stack *stack;

    if (!stack) //   || (strlen((char *)add) + stack->capacity >= stack->capacity + 1))
       stack = alloc(stack);
    if (!add) // a modifier pour inclure le path du parsing
    {
        ft_bzero(stack->data, STACK_CAPACITY);
        stack->len = 1;
        stack->data[0] = '.';
        return (stack->data);
    }
    stack->data = mempush(stack->data, add, stack->len, ft_strlen((char *)add));
    stack->len += ft_strlen((const char *)add) + 1;
    ft_putendl(stack->data);
    return (stack->data);
}

void       full_listing(void *add)
{
    t_file *lst;
    lst = NULL;

    get_inf(&lst, (char *)new_path(add));
    sort_lst(&lst);
    //print(lst);
    while (lst)
    {
        if (lst->d_type == 4)
            full_listing(lst->name); 
        lst = lst->next;
    }
//    new_path(NULL);
    return ;
}
