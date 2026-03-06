/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_opps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:08:44 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 04:53:16 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*node;

	if (!stack_b || !(*stack_b))
		return ;
	node = (*stack_b);
	if (node->next == node)
		*stack_b = NULL;
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		*stack_b = node->next;
	}
	ft_lstadd_front(stack_a, node);
	write(1, "pa\n", 3);
	data->pa_count += 1;
	data->opps_count += 1;
}

void	push_b(t_list **stack_b, t_list **stack_a, t_data *data)
{
	t_list	*node;

	if (!stack_a || !(*stack_a))
		return ;
	node = (*stack_a);
	if (node->next == node)
		*stack_a = NULL;
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		*stack_a = node->next;
	}
	ft_lstadd_front(stack_b, node);
	write(1, "pb\n", 3);
	data->pb_count += 1;
	data->opps_count += 1;
}
