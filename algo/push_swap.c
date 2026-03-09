/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:53:15 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 02:12:15 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	init_target(data);
	if (data->len_stack < 2)
		return;
	if (data->len_stack == 2)
		simple_sort_two(stack_a, data);
	else if (data->len_stack == 3)
		simple_sort_three(stack_a, data);
	else if (data->len_stack == 4)
		simple_sort_four(stack_a, stack_b, data);
	else if (data->len_stack == 5)
		simple_sort_five(stack_a, stack_b, data);
	else
		simple_sort_generic(stack_a, stack_b, data);
}

 void	medium_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	size_t	i;

	init_target(data);
	init_chunk_value(data);
	while (data->chunk_count > 0)
	{
		i = data->chunk_size;
		while (i > 0 && (*stack_a))
		{
			if ((*stack_a)->index >= data->target_min
				&& (*stack_a)->index < data->target_max)
			{
				push_b(stack_b, stack_a, data);
				i--;
			}
			else
				rotate_opti(stack_a, 'a', data);
		}
		data->target_min = data->target_max;
		data->target_max = data->target_max + data->chunk_size;
		data->chunk_count--;
	}
	push_opti(stack_a, stack_b, data);
}
 void	complex_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	size_t	max_bit;
	size_t	bit;
	size_t	len;

	max_bit = get_max_bit(data->len_stack);
	bit = 0;
	while (bit < max_bit)
	{
		len = data->len_stack;
		while (len > 0)
		{
			if ((*stack_a)->index & ((size_t)1 << bit))
				rotate_a(stack_a, data);
			else
				push_b(stack_b, stack_a, data);
			len--;
		}
		len = data->len_stack;
		while (len > 0)
		{
			push_a(stack_a, stack_b, data);
			len--;
		}
		bit++;
	}
}
