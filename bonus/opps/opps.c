/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:37:48 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 18:43:38 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tmp opps.c to test
#include "../push_swap_bonus.h"
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
void	rev_rotate_a(t_list **stack_a, t_data *data)
{
	*stack_a = (*stack_a)->prev;
	write(1, "rra\n", 4);
	data->rra_count += 1;
	data->opps_count += 1;
}
void	rev_rotate_b(t_list **stack_b, t_data *data)
{
	*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
	data->rrb_count += 1;
	data->opps_count += 1;
}
void	rev_rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_data	tmp;

	tmp = *data;
	rev_rotate_a(stack_a, &tmp);
	rev_rotate_b(stack_b, &tmp);
	write(1, "rrr\n", 4);
	data->rrr_count += 1;
	data->opps_count += 1;
}
void	rotate_a(t_list **stack_a, t_data *data)
{
	*stack_a = (*stack_a)->next;
	write(1, "ra\n", 3);
	data->ra_count += 1;
	data->opps_count += 1;
}

void	rotate_b(t_list **stack_b, t_data *data)
{
	*stack_b = (*stack_b)->next;
	write(1, "rb\n", 3);
	data->rb_count += 1;
	data->opps_count += 1;
}
void	rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_data	tmp;

	tmp = *data;
	rotate_a(stack_a, &tmp);
	rotate_b(stack_b, &tmp);
	write(1, "rr\n", 3);
	data->rr_count += 1;
	data->opps_count += 1;
}
// ici toutes les opperations compatbilisees
void	swap_a(t_list **stack_a, t_data *data)
{
	int	tmp;

	// if(!(*stack_a)->prev || !(*stack_a)->next)
	//     return ;
	tmp = (*stack_a)->next->index;
	(*stack_a)->next->index = (*stack_a)->index;
	(*stack_a)->index = tmp;
	write(1, "sa\n", 3);
	data->sa_count += 1;
	data->opps_count += 1;
}
void	swap_b(t_list **stack_b, t_data *data)
{
	int	tmp;

	// if(!(*stack_b)->prev || !(*stack_b)->next)
	//     return ;
	tmp = (*stack_b)->next->index;
	(*stack_b)->next->index = (*stack_b)->index;
	(*stack_b)->index = tmp;
	write(1, "sb\n", 3);
	data->sb_count += 1;
	data->opps_count += 1;
}

void	swap_ab(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_data	tmp;

	tmp = *data;
	swap_a(stack_a, &tmp);
	swap_b(stack_b, &tmp);
	write(1, "ss\n", 3);
	data->ss_count += 1;
	data->opps_count += 1;
}
