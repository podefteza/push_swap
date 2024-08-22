/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:12:43 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/29 11:19:23 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
void	ra(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = ft_lstlast(*stack);
		*stack = (*stack)->next;
		last->next = first;
		first->next = NULL;
		write(1, "ra\n", 3);
	}
}

// rb (rotate b): Shift up all elements of stack b by 1.
// this function is implemented but is never used by the algorithm.
void	rb(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = ft_lstlast(*stack);
		*stack = (*stack)->next;
		last->next = first;
		first->next = NULL;
		write(1, "rb\n", 3);
	}
}

// rr : ra and rb at the same time.
// this function is implemented but is never used by the algorithm.
void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
