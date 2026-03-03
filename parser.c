/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:24:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/03 17:21:15 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //replace printf with our ft_printf do not forget

/* logiaue du code pour chaque tokens[j] :
           - valider format -> is_int_token(char)
           - according to the subject we only have to take int not long so just check that its between INT_MIN et INT_MAX and then atoi
            -> is token in int range
           - atoi avec pas de risque d'overflow
           - doublon ? si non creer node et ajouter a stack
*/

static int	parse_one_arg(char *arg, t_list **stack)
{
	char	**tokens;
	int		j;
	int		value;
	t_list	*new_node;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
		return (parse_error(stack, tokens));
	j = 0;
	while (tokens[j])
	{
		if (!is_token_int(tokens[j]) || !is_token_in_int_range(tokens[j]))
			return (parse_error(stack, tokens));
		value = ft_atoi(tokens[j]);
		if (!has_duplicate(*stack, value))
			return (parse_error(stack, tokens));
		new_node = node_new(value);
		if (!new_node)
			return (parse_error(stack, tokens));
		ft_node_add_back(stack, new_node);
		j++;
	}
	free_tokens(tokens);
	return (1);
}

int	parse_input(int argc, char **argv, t_list **stack, t_opts *opts)
{
	int		i;
	size_t	len;

	if (argc <= 1 || !stack || !opts)
		return (0);
	opts_init(opts);
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!parse_one_flag(argv[i], opts))
				return (parse_error(stack, NULL));
		}
		else if (!parse_one_arg(argv[i], stack))
			return (0);
		i++;
	}
	if (*stack)
	{
		len = stack_len(*stack);
		index_sort(stack, len);
	}
	return (0);
}

