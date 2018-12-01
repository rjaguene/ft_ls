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

void    alloc(t_stack **stack)
{
    t_stack tmp;

    tmp = NULL;
    if (!stack)
    {
        ft_memalloc(stack, sizeof(stack));
        ft_memaloc(stack->data, STACK_CAPACITY);
        ft_bzero(&stack, sizeof(stack));
        return ;
    }
    stack->capacity += STACK_CAPACITY;
    tmp = stack->(*data);
    ft_memalloc(stack->data, capacity)
    ft_memcpy(stack->data, tmp);
}

void    *new_path(void *add)
{
    static t_stack stack;

    if (!stack || (strlen((char *)add) + stack->capacity >= stack->capacity + 1))
        alloc(&stack);
    if (!add) // a modifier pour inclure le path du parsing
    {
        ft_bzero(stack->data, stack->len);
        stack->len = 1;
        stack->data = ".";
        return (stack->data);
    }
    stack->data + stack->len = "/"; 
    stack->len += ft_strlen((char)add) + 1;
    ft_memccpy(stack->data, add, sizeof(add));
    ft_printf("%s",(char *s)stack->data);
    return (t_stack->data);
}

void       full_listing(void *add)
{
    t_file *lst:
    
    get_inf(&lst, (char *)new_path(add));
    sort_lst(&lst);
    print(lst);
    while (lst)
    {
        if (lst->d_type = 4)
            full_listing(lst->name) 
        lst = lst->next;
    }
    new_path(NULL);
    return ;
}
