/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:06:10 by carlos-j          #+#    #+#             */
/*   Updated: 2024/09/04 11:26:20 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	initialize_stack(int argc, char **argv, t_list **stack_a,
		t_list **stack_b)
{
	int	success;

	if (argc == 2)
		success = handle_single_argument(argv[1], stack_a, stack_b);
	else
		success = handle_multiple_arguments(argc - 1, &argv[1], stack_a,
				stack_b);
	return (success);
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
	if (!success || has_duplicates(stack_a) || stack_a == NULL)
		error(&stack_a, &stack_b, NULL);
	if (is_sorted(&stack_a))
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
