/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:13:10 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/08 11:06:06 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_list **stack_a, t_list **stack_b, char **args)
{
	free_stack(stack_a);
    free_stack(stack_b);
    free_args(args);
	write(2, "Error\n", 6);
	exit(1);
}


void free_args(char **args)
{
    int i;

    if (args == NULL)
        return;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
	stack = NULL;
}
