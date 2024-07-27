/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:47:20 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/25 16:57:35 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION: isdigit tests an integer value to determine whether it is a
numeric character (digit).

RETURN VALUE: isdigit returns 0 if the character is not a digit, or a nonzero
value if it is. If the argument is EOF , 0 is returned. */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/* remove comment to test...
int	main(void)
{
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit('9'));
	printf("%d\n", ft_isdigit('k'));
	printf("%d\n", ft_isdigit('Y'));
	printf("%d\n", ft_isdigit('#'));
	printf("%d\n", ft_isdigit('4'));
	printf("%d\n", ft_isdigit('2'));
} */
