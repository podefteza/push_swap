/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:40:44 by carlos-j          #+#    #+#             */
/*   Updated: 2024/09/06 12:05:35 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	process_arguments(char *arg, t_list **stack_a, t_list **stack_b)
{
	char		**split_args;
	int			i;
	long long	*content;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (0);
	i = 0;
	while (split_args[i])
	{
		content = (long long *)malloc(sizeof(long long));
		*content = ft_atoi(split_args[i]);
		if (!content || !checker(split_args[i]) || *content > INT_MAX
			|| *content < INT_MIN)
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

int	handle_single_argument(char *arg, t_list **stack_a, t_list **stack_b)
{
	return (process_arguments(arg, stack_a, stack_b));
}

int	handle_multiple_arguments(int argc, char **argv, t_list **stack_a,
		t_list **stack_b)
{
	int	i;
	int	success;

	i = 0;
	success = 1;
	while (i < argc && success)
	{
		success = process_arguments(argv[i], stack_a, stack_b);
		i++;
	}
	return (success);
}
