/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:31:48 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/08 13:06:41 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checker(char *arg)
{
    int i = 0;
    int has_digit = 0;

    while (arg[i] == ' ' || arg[i] == '\t')
        i++;

    if (arg[i] == '\0')  // Empty argument
        return 0;

    while (arg[i] != '\0')
    {
        if (arg[i] == '+' || arg[i] == '-')
        {
            if (i > 0 && (arg[i-1] != ' ' && arg[i-1] != '\t')) // Sign not preceded by whitespace
                return 0;
            if (arg[i+1] == '\0' || !ft_isdigit(arg[i+1])) // Sign not followed by a digit
                return 0;
        }
        else if (ft_isdigit(arg[i]))
        {
            has_digit = 1;
        }
        else if (arg[i] != ' ' && arg[i] != '\t')
        {
            return 0; // Invalid character
        }
        i++;
    }

    return has_digit;
}



int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

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
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
