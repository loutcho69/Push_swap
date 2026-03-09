/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:53:18 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 20:50:21 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tmp, to delete once merged

#include "../push_swap.h"
#include "push_swap_bonus.h"

void	data_init(t_data *data)
{
	data->len_stack = 0;
	data->disorder = 0.0;
	data->target_min = 0;
	data->target_max = 0;
	data->chunk_start = 0;
	data->chunk_end = 0;
	data->chunk_count = 0;
	data->chunk_size = 0;
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
