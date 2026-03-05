/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:24:13 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/05 14:27:24 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	medium_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	size_t	i;

	data->chunk_size = my_sqrt(data->len_stack);
	data->chunk_end = data->chunk_size;
	data->chunk_start = 0;
	data->chunk_count = (data->len_stack / data->chunk_size) + 1;
	while (data->chunk_count > 0)
	{
		i = data->chunk_size;
		while (i > 0 && (*stack_a))
		{
			if ((*stack_a)->index >= data->chunk_start
				&& (*stack_a)->index < data->chunk_end)
			{
				push_b(stack_b, stack_a);
				i--;
			}
			else
				rotate_opti(stack_a, 'a',
					data->chunk_start, data->chunk_end);
		}
		data->chunk_start = data->chunk_end;
		data->chunk_end = data->chunk_end + data->chunk_size;
		data->chunk_count--;
	}
	push_opti(stack_a, stack_b, data->len_stack);
}
