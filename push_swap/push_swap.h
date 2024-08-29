/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:05:59 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/28 10:11:40 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

int					checker(char *arg);
int					is_sorted(t_list **stack);
int					is_descending(t_list **stack);
int					has_duplicates(t_list *stack);
void				error(t_list **stack_a, t_list **stack_b, char **args);
void				free_args(char **args);
void				free_stack(t_list **stack);
int					find_min(t_list *stack);
int					find_max(t_list *stack);
int					assign_indices(t_list *stack);
void				small_sort(t_list **stack_a, t_list **stack_b);
void				sort(t_list **stack_a, t_list **stack_b);
int					handle_single_argument(char *arg, t_list **stack_a,
						t_list **stack_b);
int					handle_multiple_arguments(int argc, char **argv,
						t_list **stack_a, t_list **stack_b);
long long			ft_atoi(const char *nptr);
int					ft_isdigit(int c);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack);
void				rb(t_list **stack);
void				rra(t_list **stack);
void				rrb(t_list **stack);
void				rr(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack);
void				sb(t_list **stack);
void				ss(t_list **stack_a, t_list **stack_b);

#endif
