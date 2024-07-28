/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:00:19 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/28 17:44:23 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Utility function to find the smallest value in the stack
static int smallest_value(t_list *stack)
{
    int min = *(int *)stack->content;
    while (stack)
    {
        if (*(int *)stack->content < min)
            min = *(int *)stack->content;
        stack = stack->next;
    }
    return min;
}

void small_sort(t_list **stack_a, t_list **stack_b)
{
    int count = ft_lstsize(*stack_a);
    if (count <= 1 || is_sorted(*stack_a))
        return;

    while (count > 3)
    {
        // Rotate the smallest element to the top
        int smallest = smallest_value(*stack_a);
        while (*(int *)(*stack_a)->content != smallest)
            ra(stack_a);

        // Push the smallest element to stack B
        pb(stack_a, stack_b);
        count--;
    }

    // Now stack_a contains 3 or fewer elements, sort them
    if (count == 3)
    {
        int a = *(int *)(*stack_a)->content;
        int b = *(int *)(*stack_a)->next->content;
        int c = *(int *)(*stack_a)->next->next->content;

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
    else if (count == 2)
    {
        int a = *(int *)(*stack_a)->content;
        int b = *(int *)(*stack_a)->next->content;
        if (a > b)
            sa(stack_a);
    }

    // Push back elements from stack B to stack A
    while (*stack_b)
        pa(stack_a, stack_b);
}
