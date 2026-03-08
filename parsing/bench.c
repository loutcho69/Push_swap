/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:20:47 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/09 00:48:05 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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
static char *data_strategy(t_data *data)
{
	if(data->strategy == STRAT_SIMPLE)
		return("Simple");
	else if (data->strategy == STRAT_MEDIUM)
		return("Medium");
	else if (data->strategy == STRAT_COMPLEX)
		return("Complex");
	else
		return("Adaptive");
}

void	print_bench(t_data *data) // a print sur stderr
{
	ft_printf("[bench] disorder: %f%%\n", (double)data->disorder*100);
	ft_printf("[bench] strategy: %s / %s \n", data_strategy(data),
		parse_complexity(data));
	ft_printf("[bench] total_ops: %d\n", (int)data->opps_count);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", (int)data->sa_count,
		(int)data->sb_count, (int)data->ss_count, (int)data->pa_count, (int)data->pb_count);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		(int)data->ra_count, (int)data->rb_count, (int)data->rr_count, (int)data->rra_count, (int)data->rrb_count, (int)data->rrr_count);
}
