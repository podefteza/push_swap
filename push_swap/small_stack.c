/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:00:19 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/28 16:42:07 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the index of the smallest element
static int smallest_index(t_list *stack)
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

    if (count == 2)
    {
        if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
            sa(stack_a);
    }
    else if (count == 3)
    {
        int a = *(int *)(*stack_a)->content;
        int b = *(int *)(*stack_a)->next->content;
        int c = *(int *)(*stack_a)->next->next->content;

        if (a > b && b < c && a < c)
            sa(stack_a);
        else if (a > b && b > c && a > c)
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
    else if (count >= 4)
    {
        // Rotate the smallest element to the top
        int smallest = smallest_index(*stack_a);
        while (*(int *)(*stack_a)->content != smallest)
            ra(stack_a);

        // Push the smallest element to stack B
        pb(stack_a, stack_b);

        // Recursively sort the remaining elements
        small_sort(stack_a, stack_b);

        // Push the smallest element back to stack A
        pa(stack_a, stack_b);

        // If the stack has more elements, ensure the smallest element stays at the top
        if (count == 5)
        {
            // Rotate to move the next smallest to the top, if needed
            smallest = smallest_index(*stack_a);
            while (*(int *)(*stack_a)->content != smallest)
                ra(stack_a);
        }
    }
}
