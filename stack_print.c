/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:54:57 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/18 16:16:57 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_print(t_list *stack)
{
	t_list	*curr;

	curr = stack;
	while (curr)
	{
		printf("%d", curr->content);
		if (curr->next)
			printf(" -> ");
		else
			printf(" -> NULL\n");
		curr = curr->next;
	}
	if (!stack)
		printf("NULL\n");
}
