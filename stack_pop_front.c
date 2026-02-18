/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:29:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/18 16:47:24 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list *stack_pop_front(t_list **stack)
{
    t_list *pop;
    if (stack == NULL || *stack == NULL)
        return (NULL);
    pop = *stack;
    *stack = pop->next; 
    pop->next = NULL; 
    return (pop);
}
