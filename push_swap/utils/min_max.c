/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:10:30 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/28 08:15:29 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Finds the minimum value in the list. */
int	find_min(t_list *stack)
{
	int	min;

	if (stack == NULL)
		return (-1);
	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

/* Finds the maximum value in the list. */
int	find_max(t_list *stack)
{
	int	max;

	if (stack == NULL)
		return (-1);
	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
