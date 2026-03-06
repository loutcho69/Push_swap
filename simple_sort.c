/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:08:44 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 04:54:04 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_three(t_list **stack_a, t_data *data)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		swap_a(stack_a, data);
	else if (a > b && b > c)
	{
		swap_a(stack_a, data);
		rev_rotate_a(stack_a, data);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a, data);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a, data);
		rotate_a(stack_a, data);
	}
	else if (a < b && b > c && a > c)
		rev_rotate_a(stack_a, data);
}
void	simple_sort_two(t_list **stack_a, t_data *data)
{
	if ((*stack_a)->index == 0)
		return ;
	else
		swap_a(stack_a, data);
}
void	simple_sort_four(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while ((*stack_a)->index != 0)
		rotate_opti(stack_a, 'a', data);
	push_b(stack_b, stack_a, data);
	simple_sort_three(stack_a, data);
	push_a(stack_a, stack_b, data);
}

void	simple_sort_five(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (data->target_min < 2)
	{
		while ((*stack_a)->index != data->target_min)
			rotate_opti(stack_a, 'a', data);
		push_b(stack_b, stack_a, data);
		data->target_min++;
		data->target_max++;
	}
	simple_sort_three(stack_a, data);
	while (data->target_min != 0)
	{
		push_a(stack_a, stack_b, data);
		data->target_min--;
	}
}
void	simple_sort_generic(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (data->target_min < data->len_stack)
	{
		while ((*stack_a)->index != data->target_min)
		{
			data->target_max = data->target_min + 1;
			rotate_opti(stack_a, 'a', data);
		}
		push_b(stack_b, stack_a, data);
		data->target_min++;
	}
	while (data->target_min > 0)
	{
		push_a(stack_a, stack_b, data);
		data->target_min--;
	}
}
