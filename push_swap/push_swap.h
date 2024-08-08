/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:05:59 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/08 12:41:26 by carlos-j         ###   ########.fr       */
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
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

void				assign_indices(t_list *stack);

/*checker.c: functions to verify if the string contains any character besides
signals (+-), digits and spaces, if it's sorted and if it has duplicate values*/
int					checker(char *arg);
int					is_sorted(t_list **stack);
int					has_duplicates(t_list *stack);

/*exit.c: displays the Error message and frees the mallocs of args and stack*/
void				error(t_list **stack_a, t_list **stack_b, char **args);
void				free_args(char **args);
void				free_stack(t_list **stack);

/*min_max.c: finds the minimum and maximum values in the stack*/
int					find_min(t_list *stack);
int					find_max(t_list *stack);

/*small_stack.c: sorts up to 5 numbers. has the static functions get_position,
sort_two and sort_three*/
void				small_sort(t_list **stack_a, t_list **stack_b);

/*sort.c: the algorithm to sort more than 5 numbers*/
void				sort(t_list **stack_a, t_list **stack_b);

/*split_args.c: checks the number of arguments and, if necessary, uses the split
to separate them and implement the atoi to convert them to ints*/
int					handle_single_argument(char *arg, t_list **stack_a,
						t_list **stack_b);
int					handle_multiple_arguments(int argc, char **argv,
						t_list **stack_a, t_list **stack_b);

/*utils: list of helper functions from libft*/
int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);

/*operations: allowed operations to manipulate the values in the stacks
and between them*/
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

/*for testing...*/
void				print_stack(t_list *stack);

#endif
