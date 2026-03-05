/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:59:55 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/03 17:26:56 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	flag_dispatcher(t_list **stack_a, t_list **stack_b, t_opts opts)
{
	size_t	len;

	len = stack_len(*stack_a);
	if (opts.bench)
		printf("bench active \n");
	if (opts.strat == STRAT_SIMPLE)
	{
		printf("simple strategy chosen \n");
		simple_sort(stack_a, stack_b, len);
	}
	else if (opts.strat == STRAT_MEDIUM)
		printf("medium strategy chosen \n");
	else if (opts.strat == STRAT_COMPLEX)
		printf("complex strategy chosen \n");
	else
		printf("adaptive strategy chosen by default \n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_opts	opts;
	float	d;

	stack_a = NULL;
	stack_b = NULL;
	parse_input(argc, argv, &stack_a, &opts);
	if (!stack_a)
		return (0);

	d = disorder(stack_a);
	printf("disorder = %.3f\n", d);
	printf("This is stack_a : ");
	stack_print(stack_a);
	printf("This is stack_b : ");
	stack_print(stack_b);
	flag_dispatcher(&stack_a, &stack_b, opts);
	printf("This is stack_a : ");
	stack_print(stack_a);

	/*	TODO
	-> il reste a faire la fonction de benchmark qui must display after sorting
	- The computed disorder (% with two decimals) ici on l'a dans d
	- The name of the strategy used and its theoretical complexity class
	- The total number of operations.
	- The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
	rrr).*/


	/* choisir + exécuter la stratégie ici (simple/medium/complex/adaptive) */
	/* un prototype des fonctions de tri par exemple serait genre
	void sort_simple(t_list **a, t_list **b, const t_opts *opts)
	ou alors on rentre meme pas les opts dans la fonction juste
	on les met dans un dispatcher qui regarde l'option selectionnee et
	selon l option decide quel algo lancer*/
	/* compter les opérations dans une structure ops */
	/* si opts.bench : print sur stderr après tri */

	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
