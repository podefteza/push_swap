/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:00:19 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/27 12:56:27 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int largest_index(t_list *stack)
{
    int i;

    if (stack == NULL)
        return (0); // Handle empty stack
    i = *(int *)stack->content; // Assuming content is an integer
    while (stack)
    {
        if (*(int *)stack->content > i)
            i = *(int *)stack->content;
        stack = stack->next;
    }
    return (i);
}


// Function to check if the stack is sorted
static int is_sorted(t_list *stack)
{
    while (stack && stack->next)
    {
        if (*(int *)stack->content > *(int *)stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}


// Rotate the stack up by 1
void ra(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *first;
        t_list *last;

        first = *stack;
        last = ft_lstlast(*stack);
        *stack = (*stack)->next;
        last->next = first;
        first->next = NULL;
        write(1, "ra\n", 3);
    }
}


// Reverse rotate the stack down by 1
void rra(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *second_last;
        t_list *last;

        second_last = NULL;
        last = *stack;
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }
        second_last->next = NULL;
        last->next = *stack;
        *stack = last;
        write(1, "rra\n", 4);
    }
}


// Swap the first two elements in the stack
void sa(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (*stack && (*stack)->next)
    {
        first = *stack;
        second = (*stack)->next;
        first->next = second->next;
        second->next = first;
        *stack = second;
        write(1, "sa\n", 3);
    }
}

// Main function to sort small stacks
void small_sort(t_list **stack)
{
    int count;
    int largest;

    if (*stack == NULL || is_sorted(*stack))
        return;

    count = ft_lstsize(*stack);
    largest = largest_index(*stack);

    if (count == 2)
    {
        if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
            sa(stack);
    }
    else if (count == 3)
    {
        // Rotate until the smallest value is on top
        if (*(int *)(*stack)->content > *(int *)(*stack)->next->content
            && *(int *)(*stack)->content > *(int *)(*stack)->next->next->content)
            ra(stack);
        if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
            sa(stack);
        if (*(int *)(*stack)->next->content > *(int *)(*stack)->next->next->content)
            rra(stack);
    }
    else if (count == 4)
    {
        // Move largest to the bottom
        while (*(int *)(*stack)->content != largest)
            ra(stack);
        // Sort the remaining 3 elements
        small_sort(stack);
        // Restore stack and sort again if needed
        rra(stack);
    }
    else if (count == 5)
    {
        // Move largest to the bottom
        while (*(int *)(*stack)->content != largest)
            ra(stack);
        // Sort the remaining 4 elements
        small_sort(stack);
        // Restore stack and sort again if needed
        rra(stack);
    }
}





