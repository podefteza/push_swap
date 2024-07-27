/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:12:55 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/25 20:51:57 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new node. The member variable
’content’ is initialized with the value of the parameter ’content’. The
variable ’next’ is initialized to NULL.*/

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = malloc(sizeof(int)); // Allocate memory for the integer
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}
	*(int *)(new_node->content) = content; // Set the integer value
	new_node->next = NULL;
	return (new_node);
}
