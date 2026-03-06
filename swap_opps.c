/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_opps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:55:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 04:49:58 by lobroue          ###   ########.fr       */
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
