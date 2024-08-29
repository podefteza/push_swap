/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:06:10 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/29 14:12:14 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_args_allocation(int argc, char **argv, t_list **stack_a,
		t_list **stack_b)
{
	int		total_numbers = 0;
	int		i = 1;
	int		j;
	char	**split_args;
	char	**stack;

	// Calculate total number of numbers
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
		{
			total_numbers++;
			j++;
		}
		free_args(split_args);
		i++;
	}

	// Allocate memory for all numbers
	stack = malloc((total_numbers + 1) * sizeof(char *));
	if (!stack)
		error(stack_a, stack_b, NULL);

	// Fill the stack array
	total_numbers = 0;
	i = 1;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
		{
			stack[total_numbers] = ft_strdup(split_args[j]);
			if (!checker(stack[total_numbers]))
			{
				free_args(stack);
				free_args(split_args);
				error(stack_a, stack_b, NULL);
			}
			total_numbers++;
			j++;
		}
		free_args(split_args);
		i++;
	}
	stack[total_numbers] = NULL;

	// Handle multiple arguments
	int success = handle_multiple_arguments(total_numbers, stack, stack_a, stack_b);
	free_args(stack);
	return success;
}


long	initialize_stack(int argc, char **argv, t_list **stack_a,
		t_list **stack_b)
{
	int		success;
	char	**split_args;
	int		i;

	if (argc == 2)
	{	
		split_args = ft_split(argv[1], ' ');
		i = 0;
		while (split_args[i] != NULL)
		{
			if (!checker(split_args[i]))
			{
				free_args(split_args);
				error(stack_a, stack_b, NULL);
			}
			i++;
		}
		free_args(split_args);
		success = handle_single_argument(argv[1], stack_a, stack_b);
	}
	else
		success = handle_args_allocation(argc, argv, stack_a, stack_b);
	return (success);
}




int	assign_indices(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		index;
	int		max_index;

	max_index = 0;
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
		if (index > max_index)
			max_index = index;
		current = current->next;
	}
	return (max_index);
}
// DELETE LATER!!
void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
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
	success = initialize_stack(argc, argv, &stack_a, &stack_b);
	if (!success || has_duplicates(stack_a))
		error(&stack_a, &stack_b, NULL);
	//print_stack(stack_a);
	if (stack_a == NULL)
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
	//print_stack(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
