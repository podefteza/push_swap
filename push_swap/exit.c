/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:13:10 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/21 10:57:30 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees both stacks and any allocated arguments, then prints an error message
	to the standard error (2-stderr) stream and exits the program with a
	non-zero status code. */
void	error(t_list **stack_a, t_list **stack_b, char **args)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_args(args);
	write(2, "Error\n", 6);
	exit(1);
}

/* Frees each string in the array with free(args[i]),
	then frees the array of pointers itself with free(args). */
void	free_args(char **args)
{
	int	i;

	if (args == NULL)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/* Frees all nodes in the list and sets the stack pointer to NULL. */
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
}
