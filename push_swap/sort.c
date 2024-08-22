/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:38 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/21 17:42:56 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fits_on_top(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return (0);
	return (stack_b->content < stack_a->content);
}

/* Calculates the maximum number of bits required to represent
   the largest index in the stack. */
static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* Checks if stack_b fits on top of stack_a for optimization */
static int	a_is_sorted_b_is_descending(t_list **stack_a, t_list **stack_b)
{
	return (is_sorted(stack_a) && is_descending(stack_b)
		&& fits_on_top(*stack_a, *stack_b));
}

/* Processes each bit level and optimizes movements */
static void	radix_sort(t_list **stack_a, t_list **stack_b, int i)
{
	int	size;
	int	j;

	size = ft_lstsize(*stack_a);
	j = 0;
	while (j++ < size)
	{
		if (a_is_sorted_b_is_descending(stack_a, stack_b))//delete this function by explicitly writing it in the of statement
		{
			while (*stack_b)
				pa(stack_a, stack_b);
			return ;
		}
		if ((((*stack_a)->index >> i) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}

/* Sorts the stack using radix sort algorithm */
void	sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	i;

	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		radix_sort(stack_a, stack_b, i);
		i++;
	}
}
