/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_opps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:55:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/28 03:12:09 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ici toutes les opperations compatbilisees

void    swap_a(t_list **stack_a)
{
    //sa : swap a - swap the first 2 elements at the top of stack a.
    //Do nothing if there is only one or no elements).
    int tmp;
    
    if(!(*stack_a)->prev || !(*stack_a)->next)
        return;
    tmp = (*stack_a)->next->value;
    (*stack_a)->next->value = (*stack_a)->value;
    (*stack_a)->value = tmp;
}
void    swap_b(t_list **stack_b)
{
    //sa : swap b - swap the first 2 elements at the top of stack b.
    //Do nothing if there is only one or no elements).
    int tmp;
    
    if(!(*stack_b)->prev || !(*stack_b)->next)
        return;
    tmp = (*stack_b)->next->value;
    (*stack_b)->next->value =(*stack_b)->value;
    (*stack_b)->value = tmp;
}

void    swap_ab(t_list **stack_a, t_list **stack_b)
{
    // ss : sa and sb at the same time.
    swap_a(stack_a);
    swap_b(stack_b);
}

void    push_a(t_list   **stack_a, t_list **stack_b)
{
    // pa : push a - take the first element at the top of b and put it at the top of a. 
    // Do nothing if b is empty.
    t_list *node;
    
    if (!(*stack_b) || !stack_b)
        return;
    node = (*stack_b);
    if (node->next == node)
        *stack_b = NULL;
    else
    {
        
        node->next->prev =node->prev;
        node->prev->next = node->next;
        *stack_b = node->next;
    }
    ft_lstadd_front(stack_a, node);
}
// void    push_a(t_list **stack_a, t_list **stack_b)
// {
//     t_list *node;

//     if (!stack_b || !(*stack_b))
//         return ;
//     node = *stack_b;
//     if (node->next == node)
//         *stack_b = NULL;
//     else
//     {
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//         *stack_b = node->next;
//     }
//     ft_lstadd_front(stack_a, node);
// }
// void    push_b(t_list   **stack_a, t_list **stack_b)
// {
//     // pb : push b - take the first element at the top of a and put it at the top of b. 
//     // Do nothing if a is empty.
//     t_list *tmp;
//     t_list *node;
    
//     if (!(*stack_a) || !stack_a)
//     return;
//     node = *stack_a;
//     (*stack_a)->prev->next = node->next;
//     (*stack_a)->next->prev = node->prev;
//     tmp = *stack_a;
//     *stack_a = (*stack_a)->next;
//     if ((*stack_b)->next || (*stack_b)->prev)
//         ft_lstadd_front(stack_b,  node);
//     else
//          *stack_b = node;
// }
// void    push_b(t_list **stack_a, t_list **stack_b)
// {
//     t_list *node;

//     if (!stack_a || !(*stack_a))
//         return ;
//     node = *stack_a;

//     if (node->next == node)
//         *stack_a = NULL;
//     else
//     {
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//         *stack_a = node->next;
//     }
//     if (!(*stack_b))
//     {
//         node->next = node;
//         node->prev = node;
//         *stack_b = node;
//     }
//     else
//         ft_lstadd_front(stack_b, node);
// }
void    push_b(t_list   **stack_b, t_list **stack_a)
{
    // pa : push a - take the first element at the top of b and put it at the top of a. 
    // Do nothing if b is empty.
    printf("push_b appelée, stack_a: %p, stack_b: %p\n", *stack_a, *stack_b);
    t_list *node;
    
    if (!(*stack_a) || !stack_a)
        return;
    printf("okok");
    node = (*stack_a);
    
    printf("node: %d\n", node->value);
    printf("node->next: %p\n", node->next);
    printf("node->prev: %p\n", node->prev);
    if (node->next == node)
        *stack_a = NULL;
    else
    {
        
        node->next->prev =node->prev;
        node->prev->next = node->next;
        *stack_a = node->next;
    }
    ft_lstadd_front(stack_b, node);
    
}
void    rotate_a(t_list **stack_a)
{
    // ra : rotate a - shift up all elements of stack a by 1.
    //  The first element becomes the last one.
    
    
    // t_list *tmp;
    // tmp = stack_a;
    
    // while(len > 0)
    // {
    //     stack_a = stack_a->next;
    //     stack_a->next;
    //     len--;
    // }
    // stack_a = tmp;
    // stack_a->next;
    
    *stack_a = (*stack_a)->next;
}

void    rotate_b(t_list **stack_b)
{
    //rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
    *stack_b = (*stack_b)->next;
}
void    rotate_ab(t_list **stack_a, t_list **stack_b)
{
    // rr : ra and rb at the same time.
    rotate_a(stack_a);
    rotate_b(stack_b);
}
void    rev_rotate_a(t_list **stack_a)
{
    // rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
    *stack_a = (*stack_a)->prev;
}
void    rev_rotate_b(t_list **stack_b)
{
    // rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
    *stack_b = (*stack_b)->prev;
}
void    rev_rotate_ab(t_list **stack_a, t_list **stack_b)
{
   // rrr : rra and rrb at the same time.
    rev_rotate_a(stack_a);
    rev_rotate_b(stack_b);
}