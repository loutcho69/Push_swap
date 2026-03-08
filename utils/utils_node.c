/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:50:43 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/08 00:00:29 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// tous les utils pour la manipulation de node ici
int	count_node(t_list *stack)
{
	size_t	count;
	int		tmp;
	if(!stack)
		return(0);
	tmp = stack->value;
	count = 1;
	stack = stack->next;
	while (tmp != stack->value)
	{
		++count;
		stack = stack->next;
	}
	// ici c est return count ou count +1 jsp??
	return (count);
}
void	ft_lstadd_front(t_list **stack, t_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		(*stack)->next = (*stack);
		(*stack)->prev = (*stack);
	}
	else
	{
		new_node->prev = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->prev = res;
	res->next = res;
	res->value = content;
	return (res);
}

void	ft_lstclear(t_list **lst, int len)
{
	t_list	*tmp;

	while (len > 1)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
		len--;
	}
}
void	ft_lstadd_back(t_list **stack, t_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return ;
	}
	new_node->next = *stack;
	new_node->prev = (*stack)->prev;
	(*stack)->prev->next = new_node;
	(*stack)->prev = new_node;
}
