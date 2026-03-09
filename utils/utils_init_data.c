/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:08:44 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 13:53:17 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_values_data(t_list **stack, t_data *data)
{
	data->len_stack = count_node((*stack));
	data->opps_count = 0;
	data->sa_count = 0;
	data->sb_count = 0;
	data->ss_count = 0;
	data->pa_count = 0;
	data->pb_count = 0;
	data->ra_count = 0;
	data->rb_count = 0;
	data->rr_count = 0;
	data->rra_count = 0;
	data->rrb_count = 0;
	data->rrr_count = 0;
}

void	init_other(t_data *data)
{
	data->bench = 0;
	data->strat_forced = 0;
	data->strategy = STRAT_ADAPTIVE;
}

void	init_chunk_value(t_data *data)
{
	data->chunk_size = my_sqrt(data->len_stack);
	data->chunk_count = (data->len_stack / data->chunk_size) + 1;
	data->target_max = data->chunk_size;
}

void	init_target(t_data *data)
{
	data->target_min = 0;
	data->target_max = 1;
}
