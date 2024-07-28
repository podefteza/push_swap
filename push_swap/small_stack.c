/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:00:19 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/28 23:00:58 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Utility function to find the smallest value in the stack
static int	smallest_value(t_list *stack)
{
	int	min;

	min = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

// Utility function to get the position of a value in the stack
static int	get_position(t_list *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	count;
	int	smallest;
	int	a;
	int	b;
	int	c;

	count = ft_lstsize(*stack_a);
	if (count <= 1 || is_sorted(*stack_a))
		return ;
	while (count > 3)
	{
		// Rotate the smallest element to the top
		smallest = smallest_value(*stack_a);
		while (*(int *)(*stack_a)->content != smallest)
		{
			if (get_position(*stack_a, smallest) <= count / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		// Push the smallest element to stack B
		pb(stack_a, stack_b);
		count--;
	}
	// Now stack_a contains 3 elements, sort them
	a = *(int *)(*stack_a)->content;
	b = *(int *)(*stack_a)->next->content;
	c = *(int *)(*stack_a)->next->next->content;
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
	// Push back elements from stack B to stack A
	while (*stack_b)
		pa(stack_a, stack_b);
}
