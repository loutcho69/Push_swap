/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:41:30 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/18 15:50:22 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_clear(t_list **stack)
{
    t_list *temp;
    t_list *curr;

    if (!stack)
        return ;
    curr = *stack;
    while (curr)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
    *stack = NULL;
}