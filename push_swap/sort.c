/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:38 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/25 14:26:32 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the largest index in the stack, then calculates the number of bits
	required to represent that index by repeatedly right-shifting the value
	until it becomes zero. */
static int	calc_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	if (head == NULL)
		return (0);
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

/* Processes each bit level and optimizes movements */
static void	radix_sort(t_list **stack_a, t_list **stack_b, int i)
{
	int	size;
	int	j;

	size = ft_lstsize(*stack_a);
	j = 0;
	while (j++ < size)
	{
		if (is_sorted(stack_a) && (*stack_b) == NULL)
			return ;
		if (is_sorted(stack_a) && is_descending(stack_b)
			&& (*stack_b)->content < (*stack_a)->content)
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
	while (*stack_b)
		pa(stack_a, stack_b);
}

/* Sorts the stack based on the indices previously assigned to the elements,
		rather than their original values.
	This function implements a radix sort algorithm, processing one bit at a
		time, starting from the least significant bit.
	For each bit position (from 0 to max_bits - 1):
		1. Iterates through all elements in stack_a.
		2. Checks the i-th bit of the index:
			If the bit is 1, the element is rotated to the bottom of stack_a (ra)
			If the bit is 0, the element is pushed to stack_b (pb)
		3. After processing all elements for the current bit, elements in stack_b
			(those with 0 in the i-th bit) are moved back to stack_a (pa).
	This process is repeated for each bit position, from the least significant
		to the most significant bit, until stack_a is fully sorted. */
void	sort(t_list **stack_a, t_list **stack_b)

{
	int	max_bits;
	int	i;

	max_bits = calc_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		radix_sort(stack_a, stack_b, i);
		i++;
	}
}
