/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:53:15 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 01:30:22 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algo simple:
// chercher le min et push dans b et ainsi de suite puis repush dans a
// il me faut ma list stack a indexer avec mon size_t count qui est le nombre de differents chiffres(de nodes)
void	simple_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	init_target(data);
	if (data->len_stack < 2)
		return;
	if (data->len_stack == 2)
		simple_sort_two(stack_a, data);
	else if (data->len_stack == 3)
		simple_sort_three(stack_a, data);
	else if (data->len_stack == 4)
		simple_sort_four(stack_a, stack_b, data);
	else if (data->len_stack == 5)
		simple_sort_five(stack_a, stack_b, data);
	else
		simple_sort_generic(stack_a, stack_b, data);
}

 void	medium_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	size_t	i;

	init_target(data);
	init_chunk_value(data);
	while (data->chunk_count > 0)
	{
		i = data->chunk_size;
		while (i > 0 && (*stack_a))
		{
			if ((*stack_a)->index >= data->target_min
				&& (*stack_a)->index < data->target_max)
			{
				push_b(stack_b, stack_a, data);
				i--;
			}
			else
				rotate_opti(stack_a, 'a', data);
		}
		data->target_min = data->target_max;
		data->target_max = data->target_max + data->chunk_size;
		data->chunk_count--;
	}
	push_opti(stack_a, stack_b, data);
}
 void	complex_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	size_t	max_bit;
	size_t	bit;
	size_t	len;

	max_bit = get_max_bit(data->len_stack);
	bit = 0;
	while (bit < max_bit)
	{
		len = data->len_stack;
		while (len > 0)
		{
			if ((*stack_a)->index & ((size_t)1 << bit))
				rotate_a(stack_a, data);
			else
				push_b(stack_b, stack_a, data);
			len--;
		}
		len = data->len_stack;
		while (len > 0)
		{
			push_a(stack_a, stack_b, data);
			len--;
		}
		bit++;
	}
}
// #include <stdio.h>

// int	main(void)
// {
// 	t_list *stack_a;
// 	t_list *stack_b;
// 	t_data data;
// 	int len;

// 	stack_b = NULL; // tres important
// 	stack_a = ft_lstnew(1);
// 	ft_lstadd_front(&stack_a, ft_lstnew(2));
// 	ft_lstadd_front(&stack_a, ft_lstnew(0));
// 	ft_lstadd_front(&stack_a, ft_lstnew(43));
// 	ft_lstadd_front(&stack_a, ft_lstnew(12));
// 	ft_lstadd_front(&stack_a, ft_lstnew(-3));
// 	ft_lstadd_front(&stack_a, ft_lstnew(92378));
// 	ft_lstadd_front(&stack_a, ft_lstnew(-333));
// 	ft_lstadd_front(&stack_a, ft_lstnew(9090));
// 	ft_lstadd_front(&stack_a, ft_lstnew(76));
// 	ft_lstadd_front(&stack_a, ft_lstnew(45));
// 	ft_lstadd_front(&stack_a, ft_lstnew(-4));
// 	ft_lstadd_front(&stack_a, ft_lstnew(-4555));

// 	init_values_data(&stack_a, &data);

// 	// printf("stack_a: %d %d %d\n", stack_a->value,stack_a->next->value,stack_a->next->next->value);
// 	index_sort(&stack_a, data.len_stack);
// 	// printf("stack_a: %d %d %d\n", stack_a->value,stack_a->next->value,stack_a->next->next->value);
// 	// printf("stack_a: %zu %zu %zu\n",stack_a->index,stack_a->next->index,stack_a->next->next->index);
// 	complex_sort(&stack_a, &stack_b, &data);
// 	printf("stack_a: %d %d %d\n", stack_a->value, stack_a->next->value,
// 		stack_a->next->next->value);
// 	printf("stack_a: %zu %zu %zu\n", stack_a->index, stack_a->next->index,
// 		stack_a->next->next->index);
// 	printf("Count opps : %zu\n", data.opps_count);

// 	ft_lstclear(&stack_a, data.len_stack);

// 	return (0);
// }