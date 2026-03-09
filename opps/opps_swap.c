/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:55:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 13:51:10 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a, t_data *data)
{
	int	tmp;

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
