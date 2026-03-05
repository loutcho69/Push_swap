/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:20:47 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/05 16:47:51 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	parse_complexity(t_opts *opts, t_data *data)
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

	disorder_percent = data->disorder * 10000; //juste a voir de combien est le disorder pour lavoir en %
	ft_printf("[bench] disorder: ", 2);
	ft_putnbr_fd(disorder_percent, 2, 0);
	ft_printf("[bench] strategy: %s / %s\n", 2, opts->strategy, parse_complexity(opts->strategy))); //il faut aussi ecrire la theoretical complexity class
	ft_printf("[bench] total_ops: %d\n", 2, data->opss_count);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 2, data->sa,
		data->sb, data->ss, data->pa, data->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", 2,
		data->ra, data->rb, data->rr, data->rra, data->rrb, data->rrr);
}


	/*	TODO
	-> il reste a faire la fonction de benchmark qui must display after sorting
	- The computed disorder (% with two decimals) ici on l'a dans d
	- The name of the strategy used and its theoretical complexity class
	- The total number of operations.
	- The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
	rrr).*/
