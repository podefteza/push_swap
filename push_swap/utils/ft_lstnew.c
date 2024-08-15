/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:12:55 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/14 14:16:32 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new node. The member variable
’value’ is initialized with the value of the parameter ’value’. The
variable ’next’ is initialized to NULL.*/

#include "../push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;
	int		*int_content;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	int_content = (int *)content;
	new->content = *int_content;
	new->index = 0;
	new->next = NULL;
	return (new);
}
