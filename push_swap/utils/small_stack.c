/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:00:19 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/21 11:14:47 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Finds the position of a given value in the stack.
	Returns the position if found, otherwise returns -1. */
static int	get_position(t_list *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->content == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

/* Sorts a stack of two elements in ascending order. */
static void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

/* Sorts a stack of three elements using a series of swaps and rotations. */
static void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
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

/* Sorts a stack with up to 5 elements by:
	- Sorting stacks with 2 or fewer elements directly.
	- Moving elements to stack_b and sorting the remaining 3 elements.
	- Moving elements back from stack_b to stack_a. */
void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = ft_lstsize(*stack_a);
	if (count <= 2 || is_sorted(stack_a))
	{
		if (count == 2)
			sort_two(stack_a);
		return ;
	}
	while (count > 3)
	{
		while ((*stack_a)->content != find_min(*stack_a))
		{
			if (get_position(*stack_a, find_min(*stack_a)) <= count / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		count--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
