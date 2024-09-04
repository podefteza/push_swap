/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:38 by carlos-j          #+#    #+#             */
/*   Updated: 2024/09/04 12:34:55 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Assigns a ranking index to each element in the list based on its value. */
int	assign_indices(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		index;
	int		max_index;

	max_index = 0;
	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->content > compare->content)
				index++;
			compare = compare->next;
		}
		current->index = index;
		if (index > max_index)
			max_index = index;
		current = current->next;
	}
	return (max_index);
}

/* Processes elements based on the i-th bit of their index.
	For each element in stack_a:
	- Shifts the bits of the element's index i positions to the right;
	- Isolates the least significant bit (LSB) using & 1.
	If the LSB is 1, ra; otherwise, pb.
	After processing all elements, pa. */
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

/* 	Sorts the stack using radix sort based on the indices assigned.
	First calculates the max_bits needed to represent the max_index;
	Then calls radix_sort for each bit position from LSB to MSB.
	>>>>>>>>>>>> explanation of the algorithm: tinyurl.com/carlos-j-push-swap */
void	sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	i;
	int	max_index;

	max_index = assign_indices(*stack_a);
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_sort(stack_a, stack_b, i);
		i++;
	}
}
