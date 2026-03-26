/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps_bonus1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:21:19 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/26 16:54:07 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../push_swap.h"

void	rotate_a(t_list **stack_a, t_data *data)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	data->ra_count += 1;
	data->opps_count += 1;
}

void	rotate_b(t_list **stack_b, t_data *data)
{
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->next;
	data->rb_count += 1;
	data->opps_count += 1;
}

void	rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_data	tmp;

	tmp = *data;
	rotate_a(stack_a, &tmp);
	rotate_b(stack_b, &tmp);
	data->rr_count += 1;
	data->opps_count += 1;
}

void	swap_a(t_list **stack_a, t_data *data)
{
	int	tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = (*stack_a)->next->index;
	(*stack_a)->next->index = (*stack_a)->index;
	(*stack_a)->index = tmp;
	data->sa_count += 1;
	data->opps_count += 1;
}
