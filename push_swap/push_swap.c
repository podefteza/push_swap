/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:06:10 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/28 16:53:00 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// exernal functions: read, write, malloc, free, exit

// later, put the arguments handling in another file...
// display error when number > or < INT

#include "push_swap.h"

int is_sorted(t_list *stack)
{
    while (stack && stack->next)
    {
        if (*(int *)stack->content > *(int *)stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int	handle_single_argument(char *arg, t_list **stack_a, t_list **stack_b)
{
	int		i;
	char	**split_args;
	t_list	*new_node;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (0);
	i = 0;
	while (split_args[i])
	{
		if (!checker(split_args[i]))
			error(stack_a, stack_b, split_args);
		new_node = ft_lstnew(ft_atoi(split_args[i++]));
		if (!new_node)
			error(stack_a, stack_b, split_args);
		ft_lstadd_back(stack_a, new_node);
	}
	free_args(split_args);
	return (1);
}

int	handle_multiple_arguments(int argc, char **argv, t_list **stack_a,
		t_list **stack_b)
{
	int		i;
	t_list	*new_node;

	i = 1;
	while (i < argc)
	{
		if (!checker(argv[i]))
			error(stack_a, stack_b, NULL);
		new_node = ft_lstnew(ft_atoi(argv[i++]));
		if (!new_node)
			error(stack_a, stack_b, NULL);
		ft_lstadd_back(stack_a, new_node);
	}
	return (1);
}

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    int success;
    int stack_size;

    if (argc < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    if (argc == 2)
        success = handle_single_argument(argv[1], &stack_a, &stack_b);
    else
        success = handle_multiple_arguments(argc, argv, &stack_a, &stack_b);
    if (!success || has_duplicates(stack_a))
    {
        error(&stack_a, &stack_b, NULL);
        return (0);
    }
    stack_size = ft_lstsize(stack_a);
    if (stack_size <= 5)
        small_sort(&stack_a, &stack_b);

    /* REMOVE LATER
	printf("----------\n");
    printf("Stack A:\n");
    print_stack(stack_a);
	printf("----------\n");
    printf("Size of stack: %d\n", stack_size);*/

    return (0);
}

