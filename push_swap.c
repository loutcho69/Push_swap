/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:53:15 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 03:11:04 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algo simple:
// chercher le min et push dans b et ainsi de suite puis repush dans a
// il me faut ma list stack a indexer avec mon size_t count qui est le nombre de differents chiffres(de nodes)
static void simple_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
    size_t min;
    
    min = 0;
    if (data->len_stack == 2)
        simple_sort_two(stack_a);
    else if (data->len_stack == 3)
        simple_sort_three(stack_a);
    else if (data->len_stack == 5)
        simple_sort_five(stack_a, stack_b);
    else
    {
        while(min < data->len_stack)
        {
            while((*stack_a)->index != min)
                rotate_opti(stack_a, 'a', min,(min +1));
            push_b(stack_b, stack_a);
            min++;
        }
         while(min > 0)
         {
             push_a(stack_a, stack_b);
            min--;
        } 
    }
}

static void    medium_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
    size_t i;

    init_chunk_value(data);
    while(data->chunk_count > 0)
    {
        i = data->chunk_size;
        while(i > 0 && (*stack_a))
        {
            if((*stack_a)->index >= data->chunk_start && (*stack_a)->index < data->chunk_end)
            {
                push_b(stack_b, stack_a);
                i--;
            }
            else
                rotate_opti(stack_a, 'a',data->chunk_start,data->chunk_end);
        }
        data->chunk_start = data->chunk_end;
        data->chunk_end = data->chunk_end + data->chunk_size;
        data->chunk_count--;
    }
    push_opti(stack_a, stack_b, data->len_stack);
}
static void    complex_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
    size_t max_bit;
    size_t  bit;
    size_t  len;
    
    max_bit = get_max_bit(data->len_stack);
    bit = 0;
    while(bit < max_bit)
    {
        len = data->len_stack;
        while (len > 0)
        {
            if((*stack_a)->index & (1 << bit))
                rotate_a(stack_a);
            else
                push_b(stack_b, stack_a);
            len--;
        }
        len = data->len_stack;
        while (len > 0)
        {
            push_a(stack_a, stack_b);
            len--;
        } 
        bit++;
    }    
}
#include <stdio.h>

int main()
{
    t_list *stack_a;
    t_list *stack_b;
    t_data data;
    int len;

    stack_b = NULL;
    stack_a = ft_lstnew(1);
    ft_lstadd_front(&stack_a, ft_lstnew(2));
    ft_lstadd_front(&stack_a, ft_lstnew(0));
    ft_lstadd_front(&stack_a, ft_lstnew(43));
    ft_lstadd_front(&stack_a, ft_lstnew(12));
    // ft_lstadd_front(&stack_a, ft_lstnew(-3));
    // ft_lstadd_front(&stack_a, ft_lstnew(92378));
    // ft_lstadd_front(&stack_a, ft_lstnew(-333));
    // ft_lstadd_front(&stack_a, ft_lstnew(0));
    // ft_lstadd_front(&stack_a, ft_lstnew(76));
    // ft_lstadd_front(&stack_a, ft_lstnew(45));
    // ft_lstadd_front(&stack_a, ft_lstnew(-4));
    // ft_lstadd_front(&stack_a, ft_lstnew(-4555));

    data.len_stack = count_node(stack_a);

    printf("stack_a: %d %d %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);
    index_sort(&stack_a,data.len_stack);
    printf("stack_a: %d %d %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);
    printf("stack_a: %zu %zu %zu\n", stack_a->index, stack_a->next->index, stack_a->next->next->index);
    simple_sort(&stack_a, &stack_b, &data);
    printf("stack_a: %d %d %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);
    printf("stack_a: %zu %zu %zu\n", stack_a->index, stack_a->next->index, stack_a->next->next->index);
    
    ft_lstclear(&stack_a, len);
    
    return 0;
}