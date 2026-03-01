/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:53:15 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/01 02:57:20 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// algo simple:
// chercher le min et push dans b et ainsi de suite puis repush dans a
// il me faut ma list stack a indexer avec mon size_t count qui est le nombre de differents chiffres(de nodes)
static void simple_sort(t_list **stack_a, t_list **stack_b, size_t len)
{
    size_t min;
    
    min = 0;
    while(min < len)
    {
        while((*stack_a)->index != min)
            rotate_a(stack_a);
        push_b(stack_b, stack_a);
        min++;
    }
     while(min > 0)
     {
         push_a(stack_a, stack_b);
        min--;
     }
}
// void    medium_sort(t_list *stack_a, t_list *stack_b)
// {
    
// }
// void    complex_sort()
// {

// }
#include <stdio.h>

int main()
{
    t_list *stack_a;
    t_list *stack_b;
    int len;

    stack_b = NULL;
    stack_a = ft_lstnew(84);
    ft_lstadd_front(&stack_a, ft_lstnew(-12));
    ft_lstadd_front(&stack_a, ft_lstnew(3));
    len = count_node(stack_a);

    
    printf("oko\n");
    index_sort(&stack_a,len);
    printf("okok");
    simple_sort(&stack_a, &stack_b, len);
    printf("stack_a: %d %d %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);
    printf("stack_a: %d %d %d\n", stack_a->index, stack_a->next->index, stack_a->next->next->index);
    
    ft_lstclear(&stack_a, len);
    
    return 0;
}