/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:20:47 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 23:29:16 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*parse_complexity(t_data *data)
{
	if (data->strategy == STRAT_SIMPLE)
		return ("O(n2)");
	else if (data->strategy == STRAT_MEDIUM)
		return ("O(n√n)");
	else if (data->strategy == STRAT_COMPLEX)
		return ("O(nlogn)");
	else
	{
		if (data->disorder < 0.2)
			return ("O(n2)");
		else if (data->disorder < 0.5)
			return ("O(n√n)");
		else
			return ("O(nlogn)");
	}
}

void	print_bench(t_data *data) // a print sur stderr
{
	int	disorder_percent;

	disorder_percent = data->disorder * 100;
	printf("[bench] disorder: %d\n", disorder_percent);
	printf("[bench] strategy: %u / %s\n", data->strategy,
		parse_complexity(data));
	printf("[bench] total_ops: %zu\n", data->opps_count);
	printf("[bench] sa: %zu, sb: %zu, ss: %zu, pa: %zu, pb: %zu\n", data->sa_count,
		data->sb_count, data->ss_count, data->pa_count, data->pb_count);
	printf("[bench] ra: %zu8, rb: %zu, rr: %zu, rra: %zu, rrb: %zu, rrr: %zu\n",
		data->ra_count, data->rb_count, data->rr_count, data->rra_count, data->rrb_count, data->rrr_count);
}
