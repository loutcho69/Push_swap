/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:08:44 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 13:50:44 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
