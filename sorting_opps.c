/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_opps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:55:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/26 02:05:35 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ici toutes les opperations compatbilisees

void    swap_a(t_list *stack_a)
{
    //sa : swap a - swap the first 2 elements at the top of stack a.
    //Do nothing if there is only one or no elements).
    int tmp;
    
    if(!stack_a->prev || !stack_a->next)
        return;
    tmp = stack_a->next->value;
    stack_a->next->value =stack_a->value;
    stack_a->value = tmp;
}
void    swap_b(t_list *stack_b)
{
    //sa : swap b - swap the first 2 elements at the top of stack b.
    //Do nothing if there is only one or no elements).
    int tmp;
    
    if(!stack_b->prev || !stack_b->next)
        return;
    tmp = stack_b->next->value;
    stack_b->next->value =stack_b->value;
    stack_b->value = tmp;
}

void    swap_ab(t_list *stack_a, t_list *stack_b)
{
    // ss : sa and sb at the same time.
    swap_a(stack_a);
    swap_b(stack_b);
}

void    push_a(t_list   *stack_a, t_list *stack_b)
{
    // pa : push a - take the first element at the top of b and put it at the top of a. 
    // Do nothing if b is empty.
    if (!stack_b->value)
        return;
    if (stack_a->next || stack_a->prev)
        ft_lstadd_front(&stack_a,  lstcpy(stack_b));
    else
         lstcpy(stack_b);
    stack_b->prev->next = stack_b->next;
    stack_b->next->prev = stack_b->prev;
    ft_lstdelone(stack_b);
}

void    push_b(t_list   *stack_a, t_list *stack_b)
{
    // pb : push b - take the first element at the top of a and put it at the top of b. 
    // Do nothing if b is empty.
    if (!stack_a->value)
        return;
    if (stack_b->next || stack_b->prev)
        ft_lstadd_front(&stack_b,  lstcpy(stack_a));
    else
         lstcpy(stack_a);
    stack_a->prev->next = stack_a->next;
    stack_a->next->prev = stack_a->prev;
    ft_lstdelone(stack_a);
}
void    rotate_a(t_list *stack_a)
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
    
    stack_a->next;
}

void    rotate_b(t_list *stack_b)
{
    //rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
    stack_b->next;
}
void    rotate_ab(t_list *stack_a, t_list *stack_b)
{
    // rr : ra and rb at the same time.
    rotate_a(stack_a);
    rotate_b(stack_b);
}
void    rev_rotate_a(t_list *stack_a)
{
    // rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
    stack_a->prev;
}
void    rev_rotate_b(t_list *stack_b)
{
    // rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
    stack_b->prev;
}
void    rev_rotate_ab(t_list *stack_a, t_list *stack_b)
{
   // rrr : rra and rrb at the same time.
    rev_rotate_a(stack_a);
    rev_rotate_b(stack_b);
}