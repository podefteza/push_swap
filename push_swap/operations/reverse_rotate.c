/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:12:41 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/31 11:39:54 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
void	rra(t_list **stack)
{
	t_list	*second_last;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
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

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
void	rrb(t_list **stack)
{
	t_list	*second_last;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
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
		write(1, "rrb\n", 4);
	}
}

// rrr : rra and rrb at the same time.
void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
