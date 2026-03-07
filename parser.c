/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:08:44 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/08 00:00:43 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:24:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/06 22:36:16 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		new_node = ft_lstnew(value);
		if (!new_node)
			return (parse_error(stack, tokens));
		ft_lstadd_back(stack, new_node);
		j++;
	}
	free_tokens(tokens);
	return (1);
}

int	parse_input(int argc, char **argv, t_list **stack, t_data *data)
{
	int		i;

	if (argc <= 1 || !stack)
		return (0);
	init_values_data(stack, data);
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!parse_one_flag(argv[i], data))
				return (parse_error(stack, NULL));
		}
		else if (!parse_one_arg(argv[i], stack))
			return (0);
		i++;
	}
	init_values_data(stack, data);
	if (*stack)
		index_sort(stack, data->len_stack);
	return (0);
}
