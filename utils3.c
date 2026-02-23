/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:30:53 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/23 13:37:18 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_lstadd_front(t_list **stack, t_list *node)
{
    if (!stack || !node)
        return ;
    node->next = *stack;
    *stack = node;
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}