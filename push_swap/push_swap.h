/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:05:59 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/28 17:34:36 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					checker(char *arg);
void				free_args(char **args);
void				error(t_list **stack_a, t_list **stack_b, char **args);
void				free_stack(t_list **stack);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				print_stack(t_list *stack);
int					has_duplicates(t_list *stack);
void small_sort(t_list **stack_a, t_list **stack_b);
int					is_sorted(t_list *stack);
void				ra(t_list **stack);
void				rra(t_list **stack);
void				sa(t_list **stack);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void sb(t_list **stack);
void ss(t_list **stack_a, t_list **stack_b);
void rb(t_list **stack);
void rr(t_list **stack_a, t_list **stack_b);
void rrb(t_list **stack);
void rrr(t_list **stack_a, t_list **stack_b);

#endif
