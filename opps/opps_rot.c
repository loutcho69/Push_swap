/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:08:44 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/26 16:56:34 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a, t_data *data)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	write(1, "ra\n", 3);
	data->ra_count += 1;
	data->opps_count += 1;
}

void	rotate_b(t_list **stack_b, t_data *data)
{
	if (!stack_b || !*stack_b)
		return ;
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
