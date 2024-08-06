/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:31:48 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/06 12:35:44 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(char *arg)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (!arg[i])
		return (0);
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]))
			has_digit = 1;
		else if ((arg[i] == '+' || arg[i] == '-')
			&& (arg[i - 1] == '+' || arg[i - 1] == '-'))
			return (0);
		else if (arg[i] != ' ' && arg[i] != '\t')
			return (0);
		i++;
	}
	return (has_digit);
}

int has_duplicates(t_list *stack)
{
    t_list *current;
    t_list *runner;

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
