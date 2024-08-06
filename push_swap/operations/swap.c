/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:12:45 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/29 11:20:54 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
void	sa(t_list **stack)
{
	t_list	*first;
	t_list	*second;

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

// sb (swap b): Swap the first 2 elements at the top of stack b.
void	sb(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
		write(1, "sb\n", 3);
	}
}

// ss : sa and sb at the same time.
void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
