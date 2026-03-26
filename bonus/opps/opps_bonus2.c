/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:22:34 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/26 16:54:38 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../push_swap_bonus.h"

void	swap_b(t_list **stack_b, t_data *data)
{
	int	tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = (*stack_b)->next->index;
	(*stack_b)->next->index = (*stack_b)->index;
	(*stack_b)->index = tmp;
	data->sb_count += 1;
	data->opps_count += 1;
}

void	swap_ab(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_data	tmp;

	tmp = *data;
	swap_a(stack_a, &tmp);
	swap_b(stack_b, &tmp);
	data->ss_count += 1;
	data->opps_count += 1;
}
