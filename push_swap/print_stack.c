/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:46:02 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/21 11:04:00 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Prints the stack. For testing purposes... */
void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}
