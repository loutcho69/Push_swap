#include "../../push_swap.h"

/* checker-compatible ops: no printing, no data counters */

void	sa(t_list **stack_a)
{
    int tmp;

    if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
        return ;
    tmp = (*stack_a)->next->index;
    (*stack_a)->next->index = (*stack_a)->index;
    (*stack_a)->index = tmp;
}

void	sb(t_list **stack_b)
{
    int tmp;

    if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
        return ;
    tmp = (*stack_b)->next->index;
    (*stack_b)->next->index = (*stack_b)->index;
    (*stack_b)->index = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
    t_list *node;

    if (!stack_b || !*stack_b)
        return ;
    node = (*stack_b);
    if (node->next == node)
        *stack_b = NULL;
    else
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        *stack_b = node->next;
    }
    ft_node_add_front(stack_a, node);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
    t_list *node;

    if (!stack_a || !*stack_a)
        return ;
    node = (*stack_a);
    if (node->next == node)
        *stack_a = NULL;
    else
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        *stack_a = node->next;
    }
    ft_node_add_front(stack_b, node);
}

void	ra(t_list **stack_a)
{
    if (!stack_a || !*stack_a)
        return ;
    *stack_a = (*stack_a)->next;
}

void	rb(t_list **stack_b)
{
    if (!stack_b || !*stack_b)
        return ;
    *stack_b = (*stack_b)->next;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void	rra(t_list **stack_a)
{
    if (!stack_a || !*stack_a)
        return ;
    *stack_a = (*stack_a)->prev;
}

void	rrb(t_list **stack_b)
{
    if (!stack_b || !*stack_b)
        return ;
    *stack_b = (*stack_b)->prev;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
