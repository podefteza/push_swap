/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:06:10 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/26 14:31:56 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// exernal functions: read, write, malloc, free, exit

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;
    int     i;
    t_list  *new_node;
    char    **split_args;

    if (argc < 2)
        return (0);

    stack_a = NULL;
    stack_b = NULL;

    // Handle case where a single argument containing numbers is passed
    if (argc == 2)
    {
        // Split the single argument string into individual numbers
        split_args = ft_split(argv[1], ' ');
        if (!split_args)
        {
            error(&stack_a, &stack_b);
            return (0);
        }

        // Validate each split argument
        i = 0;
        while (split_args[i])
        {
            if (!checker(split_args[i]))
            {
                error(&stack_a, &stack_b);
                // Free the split arguments
                while (split_args[i])
                    free(split_args[i++]);
                free(split_args);
                return (0);
            }
            i++;
        }

        // Build the stack_a from the split arguments
        i = 0;
        while (split_args[i])
        {
            new_node = ft_lstnew(ft_atoi(split_args[i]));
            if (!new_node)
            {
                error(&stack_a, &stack_b);
                // Free the split arguments
                while (split_args[i])
                    free(split_args[i++]);
                free(split_args);
                return (0);
            }
            ft_lstadd_back(&stack_a, new_node);
            i++;
        }

        // Free the split arguments
        while (split_args[i])
            free(split_args[i++]);
        free(split_args);
    }
    else
    {
        // Handle multiple arguments
        i = 1;
        while (i < argc)
        {
            if (!checker(argv[i]))
            {
                error(&stack_a, &stack_b);
                return (0);
            }
            new_node = ft_lstnew(ft_atoi(argv[i]));
            if (!new_node)
            {
                error(&stack_a, &stack_b);
                return (0);
            }
            ft_lstadd_back(&stack_a, new_node);
            i++;
        }
    }

	if (has_duplicates(stack_a))
    {
        error(&stack_a, &stack_b);
        return (0);
    }

    /* Print the stack_a to verify correctness REMOVE LATER*/
    printf("Stack A:\n");
    print_stack(stack_a);
	printf("Size of stack: %d\n", ft_lstsize(stack_a));
    return (0);
}

