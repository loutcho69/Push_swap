/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:20:47 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/06 23:07:50 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*parse_complexity(t_opts *opts, t_data *data)
{
	if (opts->strategy == STRAT_SIMPLE)
		return ("O(n2)");
	else if (opts->strategy == STRAT_MEDIUM)
		return ("O(n√n)");
	else if (opts->strategy == STRAT_COMPLEX)
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

int	print_bench(t_data *data, t_opts *opts) // a print sur stderr
{
	int	disorder_percent;

	disorder_percent = data->disorder * 100;
	ft_printf("[bench] disorder: %d\n", disorder_percent);
	ft_printf("[bench] strategy: %s / %s\n", opts->strategy,
		parse_complexity(opts->strategy, data));
	ft_printf("[bench] total_ops: %d\n", data->opps_count);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", data->sa_count,
		data->sb_count, data->ss_count, data->pa_count, data->pb_count);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		data->ra_count, data->rb_count, data->rr_count, data->rra_count, data->rrb_count, data->rrr_count);
}
