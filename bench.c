/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:20:47 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/06 22:35:27 by btheveny         ###   ########.fr       */
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
		parse_complexity(opts->strategy));
	ft_printf("[bench] total_ops: %d\n", data->opss_count);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", data->sa,
		data->sb, data->ss, data->pa, data->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		data->ra, data->rb, data->rr, data->rra, data->rrb, data->rrr);
}
