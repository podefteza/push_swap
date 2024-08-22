/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:40:44 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/21 11:33:08 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Splits a single argument string into multiple arguments using ft_split,
	converts each argument to an integer using ft_atoi, and adds each integer
	as a new node to stack_a. Handles memory allocation and performs error
	checking for each argument and node creation. */
int	handle_single_argument(char *arg, t_list **stack_a, t_list **stack_b)
{
	int		i;
	char	**split_args;
	t_list	*new_node;
	int		*content;

	split_args = ft_split(arg, ' ');
	if (split_args == NULL)
		return (0);
	i = 0;
	while (split_args[i])
	{
		content = (int *)malloc(sizeof(int));
		if (checker(split_args[i]) == 0 || (content == NULL))
			error(stack_a, stack_b, split_args);
		*content = ft_atoi(split_args[i]);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
			error(stack_a, stack_b, split_args);
		ft_lstadd_back(stack_a, new_node);
		i++;
		free(content);
	}
	free_args(split_args);
	return (1);
}

/* Processes multiple command-line arguments, converting each to an integer,
	and adds each integer as a new node to stack_a.
	Handles memory allocation and error checking for each argument. */
int	handle_multiple_arguments(int argc, char **argv, t_list **stack_a,
		t_list **stack_b)
{
	int		i;
	t_list	*new_node;
	int		*content;

	i = 1;
	while (i < argc)
	{
		content = (int *)malloc(sizeof(int));
		if (checker(argv[i]) == 0 || (content == NULL))
			error(stack_a, stack_b, NULL);
		*content = ft_atoi(argv[i]);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			free(content);
			error(stack_a, stack_b, NULL);
		}
		ft_lstadd_back(stack_a, new_node);
		i++;
		free(content);
	}
	return (1);
}
