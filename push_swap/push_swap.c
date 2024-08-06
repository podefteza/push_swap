/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:06:10 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/06 13:27:35 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// exernal functions: read, write, malloc, free, exit

// handle case: ./push_swap "1 2 3" 5 4

#include "push_swap.h"

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

int main(int argc, char **argv) {
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

    if (!success || has_duplicates(stack_a)) {
        error(&stack_a, &stack_b, NULL);
        return (0);
    }

    stack_size = ft_lstsize(stack_a);

    if (stack_size <= 500)
        small_sort(&stack_a, &stack_b);
    //else
        //sort(&stack_a, &stack_b);
/**/
    printf("----------\n");
    printf("Sorted Stack A:\n");
    print_stack(stack_a);
    printf("----------\n");

    return (0);
}
