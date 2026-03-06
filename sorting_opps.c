/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_opps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:55:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 04:08:10 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ici toutes les opperations compatbilisees
void	swap_a(t_list **stack_a, t_data *data)
{
	int	tmp;

	// sa : swap a - swap the first 2 elements at the top of stack a.
	// Do nothing if there is only one or no elements).
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

	// sa : swap b - swap the first 2 elements at the top of stack b.
	// Do nothing if there is only one or no elements).
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

	// ss : sa and sb at the same time.
	tmp = *data;
	swap_a(stack_a, &tmp);
	swap_b(stack_b, &tmp);
	write(1, "ss\n", 3);
	data->ss_count += 1;
	data->opps_count += 1;
}

void	push_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*node;

	// pa : push a- take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
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

	// pb : push b- take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
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
void	rotate_a(t_list **stack_a, t_data *data)
{
	// ra : rotate a - shift up all elements of stack a by 1.
	//  The first element becomes the last one.
	*stack_a = (*stack_a)->next;
	write(1, "ra\n", 3);
	data->ra_count += 1;
	data->opps_count += 1;
}

void	rotate_b(t_list **stack_b, t_data *data)
{
	// rb : rotate b- shift up all elements of stack b by 1. The first element becomes the last one.
	*stack_b = (*stack_b)->next;
	write(1, "rb\n", 3);
	data->rb_count += 1;
	data->opps_count += 1;
}
void	rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_data	tmp;

	// rr : ra and rb at the same time.
	tmp = *data;
	rotate_a(stack_a, &tmp);
	rotate_b(stack_b, &tmp);
	write(1, "rr\n", 3);
	data->rr_count += 1;
	data->opps_count += 1;
}
void	rev_rotate_a(t_list **stack_a, t_data *data)
{
	// rra : reverse rotate a- shift down all elements of stack a by 1. The last element becomes the first one.
	*stack_a = (*stack_a)->prev;
	write(1, "rra\n", 4);
	data->rra_count += 1;
	data->opps_count += 1;
}
void	rev_rotate_b(t_list **stack_b, t_data *data)
{
	// rrb : reverse rotate b- shift down all elements of stack b by 1. The last element becomes the first one.
	*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
	data->rrb_count += 1;
	data->opps_count += 1;
}
void	rev_rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_data	tmp;

	// rrr : rra and rrb at the same time.
	tmp = *data;
	rev_rotate_a(stack_a, &tmp);
	rev_rotate_b(stack_b, &tmp);
	write(1, "rrr\n", 4);
	data->rrr_count += 1;
	data->opps_count += 1;
}
