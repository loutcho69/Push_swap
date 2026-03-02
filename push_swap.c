/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:53:15 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/02 10:59:55 by lobroue          ###   ########.fr       */
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
static void    medium_sort(t_list **stack_a, t_list **stack_b, size_t len)
{
    size_t  len1;
    size_t len2;
    size_t chunk_start;
    size_t chunk_end;
    size_t index;
    size_t  chunk_count;

    chunk_end = my_sqrt(len);
    chunk_start = 0;
    len1 = len;
    index = len - 1;
    chunk_count = len / my_sqrt(len);
    
    while(chunk_count > 0)
    {
        len2 = len;
        while( len2 > 0)
        {
            if((*stack_a)->index >= chunk_start && (*stack_a)->index < chunk_end)
                push_b(&stack_b, &stack_a);
            else
                rotate_a(&stack_a);
            len2--;
        }
        chunk_start = chunk_end;
        chunk_end = chunk_end + my_sqrt(len);
        chunk_count--;
    } 

    while(len1 > 0 )
    {
        if (r_or_rv(stack_b, index))
            while((*stack_b)->index != index)
                rotate_b(&stack_b);
        else
            while((*stack_b)->index != index)
                rev_rotate_b(&stack_b);
        push_a(&stack_a, &stack_b);
        len--;
        index--;
    }
    
}
static void    complex_sort(t_list **stack_a, t_list *stack_b, size_t len)
{
    size_t max_bit;
    size_t  bit;
    size_t  len1;
    
    max_bit = get_max_bit(len);
    bit = 0;
    while(bit <= max_bit)
    {
        len1 = len;
        while (len1 > 0)
        {
            if((!(*stack_a)->index & (1 << bit)))
                push_b(&stack_a, &stack_b);
            else
                rotate_a(&stack_a);
            len1--;
        }
        len1 = len;
        while (len1 > 0)
        {
            push_a(&stack_b, &stack_a);
            len1--;
        } 
        bit++;
    }    
}
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