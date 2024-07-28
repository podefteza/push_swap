/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:34:52 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/25 16:57:41 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	t_list(*current);
	size = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}
