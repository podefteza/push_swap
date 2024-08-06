/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:00:19 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/06 12:40:23 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_position(t_list *stack, int value)
{
    int position = 0;

    while (stack)
    {
        if (stack->value == value)
            return position;
        stack = stack->next;
        position++;
    }
    return -1;
}

static void sort_three_or_less(t_list **stack_a)
{
    int a, b, c;

    if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
        return;

    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;

    if (a > b && b < c && a < c)
        sa(stack_a);
    else if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}

void small_sort(t_list **stack_a, t_list **stack_b)
{
    int count;
    int smallest;

    count = ft_lstsize(*stack_a);
    if (count <= 1 || is_sorted(stack_a))
        return;

    while (count > 3)
    {
        smallest = find_min(*stack_a);
        while ((*stack_a)->value != smallest)
        {
            if (get_position(*stack_a, smallest) <= count / 2)
                ra(stack_a);
            else
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        count--;
    }
    sort_three_or_less(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
}
