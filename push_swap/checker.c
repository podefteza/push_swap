/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:31:48 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/29 14:01:53 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if a given string 'arg' represents a valid number.
- It skips any leading spaces or tabs.
- If a '+' or '-' sign is present, it ensures that the sign is either the
	first non-space character or follows a space/tab and is followed by a digit.
- If the sign is not followed by a digit or is found in an invalid position,
	the function returns 0.
- If the string ends with a non-digit character, the function also returns 0.
- The 'has_digit' variable is set to 1 and the function returns 1 if the string
	is a valid number (contains only digits and optional signs), or 0 if it
	contains any invalid characters. */
int	checker(char *arg)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (arg[i] == ' ' || arg[i] == '\t')
		i++;
	if (arg[i] == '\0' || ((arg[i] == '+' || arg[i] == '-')
			&& (arg[i + 1] == '\0' || !ft_isdigit(arg[++i]))))
		return (0);
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]))
			has_digit = 1;
		else if ((arg[i] == '+' || arg[i] == '-') && (!ft_isdigit(arg[i + 1])
				|| (arg[i - 1] != ' ' && arg[i - 1] != '\t')))
			return (0);
		else if (arg[i] != ' ' && arg[i] != '\t')
			return (0);
		i++;
	}
	return (has_digit);
}

/* Checks if the list is already sorted. If so, returns 1. */
int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

/* Checks if the list is in descending order. If so, returns 1. */
int	is_descending(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content < head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

/* Checks if the list has any duplicate value. If so, returns 1. */
int	has_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*runner;

	if (!stack)
		return (0);
	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
