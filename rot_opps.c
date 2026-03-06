/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing copy 2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:08:44 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 04:48:29 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
