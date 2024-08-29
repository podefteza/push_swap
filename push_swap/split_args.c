/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:40:44 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/29 11:33:37 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_creation(long long *content, t_list **stack_a, t_list **stack_b)
{
	t_list	*new_node;

	new_node = ft_lstnew((int *)content);
	if (new_node == NULL)
	{
		free(content);
		error(stack_a, stack_b, NULL);
	}
	ft_lstadd_back(stack_a, new_node);
	free(content);
}

/* Splits a single argument string into multiple arguments using ft_split,
	converts each argument to an integer using ft_atoi, and adds each integer
	as a new node to stack_a. Handles memory allocation and performs error
	checking for each argument and node creation. */
int	handle_single_argument(char *arg, t_list **stack_a, t_list **stack_b)
{
	int			i;
	char		**split_args;
	long long	*content;

	split_args = ft_split(arg, ' ');
	if (split_args == NULL)
		return (0);
	i = 0;
	while (split_args[i])
	{
		content = (long long *)malloc(sizeof(long long));
		if (content == NULL)
			error(stack_a, stack_b, split_args);
		*content = ft_atoi(split_args[i]);
		if (*content > INT_MAX || *content < INT_MIN)
		{
			free(content);
			error(stack_a, stack_b, split_args);
		}
		node_creation(content, stack_a, stack_b);
		i++;
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
	int			i;
	long long	*content;

	i = 0;
	while (i < argc)
	{
		content = (long long *)malloc(sizeof(long long));
		if (content == NULL)
			error(stack_a, stack_b, NULL);
		*content = ft_atoi(argv[i]);
		if (*content > INT_MAX || *content < INT_MIN)
		{
			free(content);
			error(stack_a, stack_b, argv);
		}
		node_creation(content, stack_a, stack_b);
		i++;
	}
	return (1);
}
