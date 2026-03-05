/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:59:55 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/05 16:34:25 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//les branchements avec les algos de tri vont se faire ici dans le flag dispatcher

static int	flag_dispatcher(t_list **stack_a, t_list **stack_b,
	t_opts *opts, t_data *data)
{
	size_t	len;

	len = stack_len(*stack_a);
	if (opts->bench)
		printf("bench active \n");
	if (opts->strategy == STRAT_SIMPLE)
	{
		printf("simple strategy chosen \n");
		simple_sort(stack_a, stack_b, len);
	}
	else if (opts->strategy == STRAT_MEDIUM)
	{
		printf("medium strategy chosen \n");
		medium_sort(stack_a, stack_b, data);
	}
	else if (opts->strategy == STRAT_COMPLEX)
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
	t_data	data;
	float	d;

	stack_a = NULL;
	stack_b = NULL;
	parse_input(argc, argv, &stack_a, &opts, &data);
	if (!stack_a)
		return (0);

	d = disorder(stack_a);
	// data.disorder = d;
	printf("disorder = %.3f\n", d);
	printf("This is stack_a : ");
	stack_print(stack_a);
	printf("This is stack_b : ");
	stack_print(stack_b);
	flag_dispatcher(&stack_a, &stack_b, &opts, &data);
	printf("This is stack_a : ");
	stack_print(stack_a);




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
