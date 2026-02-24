/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:46:48 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/23 13:47:43 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	parse_error(t_list **a, char **tokens)
{
	if (tokens)
		free_tokens(tokens);
	if (a)
		stack_clear(a);
	write(2, "Error\n", 6);
	return (1);
}