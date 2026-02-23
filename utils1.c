/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:26:18 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/23 13:29:11 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list *ft_lstpop_front(t_list **stack)
{
    t_list *pop;
    if (stack == NULL || *stack == NULL)
        return (NULL);
    pop = *stack;
    *stack = pop->next; 
    pop->next = NULL; 
    return (pop);
}

void	stack_print(t_list *stack)
{
	t_list	*curr;

	curr = stack;
	while (curr)
	{
		printf("%d", curr->content);
		if (curr->next)
			printf(" >>> ");
		else
			printf(" >>> NULL\n");
		curr = curr->next;
	}
	if (!stack)
		printf("NULL\n");
}
void	stack_clear(t_list **stack)
{
    t_list *temp;
    t_list *curr;

    if (!stack)
        return ;
    curr = *stack;
    while (curr)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
    *stack = NULL;
}

t_list *node_new(int value)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = value;
    node->next = NULL;
    return (node);
}