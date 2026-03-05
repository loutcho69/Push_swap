/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:20:47 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/05 16:10:38 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_data //rajouter les opps et disorder aussi i guess
{
	size_t			len_stack;
	size_t			chunk_start;
	size_t			chunk_end;
	size_t			chunk_count;
	size_t			chunk_size;
	size_t			opps_count; //opps
}					t_data;

int	bench(t_data *data, t_opts *opts) // a print sur stderr
{

	int	disorder_percent;

	disorder_percent = data->disorder * 10000; //juste a voir de combien est le disorder
	ft_printf("[bench] disorder: ", 2);
	ft_putnbr_fd(disorder_percet, 2, 0);
	ft_printf("[bench] strategy: %s / %s\n", 2, opts->strat, parse_complexity(opts.strat))); //il faut aussi ecrire la theoretical complexity class
	ft_printf("[bench] total_ops: %d\n", 2, data->opps_count);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 2, data->sa,
		data->sb, data->ss, data->pa, data->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", 2,
		data->ra, data->rb, data->rr, data->rra, data->rrb, data->rrr);
}




}



	/*	TODO
	-> il reste a faire la fonction de benchmark qui must display after sorting
	- The computed disorder (% with two decimals) ici on l'a dans d
	- The name of the strategy used and its theoretical complexity class
	- The total number of operations.
	- The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
	rrr).*/
