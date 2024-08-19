/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:06:10 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/19 12:33:51 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_spaces(int argc, char **argv, t_list **stack_a,
		t_list **stack_b)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				error(stack_a, stack_b, NULL);
			j++;
		}
		i++;
	}
}

int	handle_args_allocation(int argc, char **argv, t_list **stack_a,
		t_list **stack_b)
{
	char	**args;
	int		i;
	int		success;

	args = malloc((argc + 1) * sizeof(char *));
	if (!args)
	{
		error(stack_a, stack_b, NULL);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!checker(argv[i]))
		{
			free_args(args);
			error(stack_a, stack_b, NULL);
		}
		args[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	args[argc - 1] = NULL;
	success = handle_multiple_arguments(argc, argv, stack_a, stack_b);
	free_args(args);
	return (success);
}

int	initialize_args(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	int	success;

	if (argc == 2)
	{
		if (!checker(argv[1]))
			error(stack_a, stack_b, NULL);
		success = handle_single_argument(argv[1], stack_a, stack_b);
	}
	else
	{
		check_for_spaces(argc, argv, stack_a, stack_b);
		success = handle_args_allocation(argc, argv, stack_a, stack_b);
	}
	return (success);
}

void	assign_indices(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->content > compare->content)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		success;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	success = initialize_args(argc, argv, &stack_a, &stack_b);
	if (!success || has_duplicates(stack_a))
		error(&stack_a, &stack_b, NULL);
	assign_indices(stack_a);
	if (is_sorted(&stack_a) == 1)
	{
		free_stack(&stack_a);
		return (0);
	}
	if (ft_lstsize(stack_a) <= 5)
		small_sort(&stack_a, &stack_b);
	else
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
