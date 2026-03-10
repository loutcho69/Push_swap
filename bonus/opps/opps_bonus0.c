/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps_bonus0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:37:48 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/10 01:40:20 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../../push_swap.h"

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
	data->pb_count += 1;
	data->opps_count += 1;
}

void	rev_rotate_a(t_list **stack_a, t_data *data)
{
	*stack_a = (*stack_a)->prev;
	data->rra_count += 1;
	data->opps_count += 1;
}

void	rev_rotate_b(t_list **stack_b, t_data *data)
{
	*stack_b = (*stack_b)->prev;
	data->rrb_count += 1;
	data->opps_count += 1;
}

void	rev_rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_data	tmp;

	tmp = *data;
	rev_rotate_a(stack_a, &tmp);
	rev_rotate_b(stack_b, &tmp);
	data->rrr_count += 1;
	data->opps_count += 1;
}
