/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:53:15 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/25 23:07:16 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// algo simple:
// chercher le min et push dans b et ainsi de suite puis repush dans a
// il me faut ma list stack a indexer avec mon size_t count qui est le nombre de differents chiffres(de nodes)
void simple_sort(t_list *stack_a, size_t count)
{
    int tmp;
    
    tmp = stack_a->value;
    while(count > 0)
    {
        stack_a = stack_a->next;
        if(stack_a->value < tmp)
            tmp = stack_a->value;
        count--;        
    }
    while(tmp != stack_a->value)
        stack_a
}
void    medium_sort(t_list *stack_a, t_list *stack_b)
{
    
}