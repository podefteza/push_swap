/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:40:44 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/03 16:15:02 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int handle_single_argument(char *arg, t_list **stack_a, t_list **stack_b)
{
    int i;
    char **split_args;
    t_list *new_node;
    int *content;

    split_args = ft_split(arg, ' ');
    if (!split_args)
        return (0);
    i = 0;
    while (split_args[i])
    {
        if (!checker(split_args[i]))
            error(stack_a, stack_b, split_args);
        content = (int *)malloc(sizeof(int));
        if (!content)
            error(stack_a, stack_b, split_args);
        *content = ft_atoi(split_args[i++]);
        new_node = ft_lstnew(content);
        if (!new_node)
        {
            free(content);
            error(stack_a, stack_b, split_args);
        }
        ft_lstadd_back(stack_a, new_node);
    }
    free_args(split_args);
    return (1);
}

int handle_multiple_arguments(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
    int i;
    t_list *new_node;
    int *content;

    i = 1;
    while (i < argc)
    {
        if (!checker(argv[i]))
            error(stack_a, stack_b, NULL);
        content = (int *)malloc(sizeof(int));
        if (!content)
            error(stack_a, stack_b, NULL);
        *content = ft_atoi(argv[i++]);
        new_node = ft_lstnew(content);
        if (!new_node)
        {
            free(content);
            error(stack_a, stack_b, NULL);
        }
        ft_lstadd_back(stack_a, new_node);
    }
    return (1);
}
