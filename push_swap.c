/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:53:15 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/28 20:09:15 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// algo simple:
// chercher le min et push dans b et ainsi de suite puis repush dans a
// il me faut ma list stack a indexer avec mon size_t count qui est le nombre de differents chiffres(de nodes)
static void simple_sort(t_list *stack_a)
{
    size_t min;
    t_list *stack_b;
    
    min = 0;
    stack_b = malloc(sizeof(t_list));
    while(stack_a)
    {
        while(stack_a->value != min)
            rotate_a(&stack_a);
        push_b(&stack_a, &stack_b);
        min++;
    }
     while(stack_b)
        push_a(&stack_a, &stack_b);
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

    stack_b = NULL;
    stack_a = ft_lstnew(3);
    ft_lstadd_front(&stack_a, ft_lstnew(2));
    ft_lstadd_front(&stack_a, ft_lstnew(1));

    printf("stack_a: %d %d %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);

    push_b(&stack_b, &stack_a);
    printf("okok");
    printf("stack_b: %p\n", stack_b);
    printf("stack_a apres push_b: %d %d\n", stack_a->value, stack_a->next->value);
    printf("okok");
    printf("stack_b apres push_b: %d\n", stack_b->value);
   
    return 0;
}