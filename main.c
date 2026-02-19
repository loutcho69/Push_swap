/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:04:08 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/19 16:42:47 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "stack.h"

int main(void)
{
    t_list *stack;
    t_list *node;
    t_list *pop;
    int i;

    stack = NULL;
    node = node_new(1);
    stack_push_front(&stack, node);
    node = node_new(2);
    stack_push_front(&stack, node);
    node = node_new(3);
    stack_push_front(&stack, node);
    node = node_new(4);
    stack_push_front(&stack, node);
    node = node_new(5);
    stack_push_front(&stack, node);
    stack_print(stack);
    pop = stack_pop_front(&stack);
    if (pop)
    {
        i = pop->content;
        printf("storing head (%d) in pop\n", i);
    }
    stack_print(stack);
    stack_push_front(&stack, pop);
    printf("adding head again with push front\n");
    stack_print(stack);
    stack_clear(&stack);
    printf("interestingly pop is freed on its own when its added back as the head\n");
    return (0);
}*/