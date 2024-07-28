/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

#include "push_swap.h"

// Push the top element from stack A to stack B
void pb(t_list **stack_a, t_list **stack_b)
{
    if (*stack_a)
    {
        t_list *temp = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next = *stack_b;
        *stack_b = temp;
        write(1, "pb\n", 3);
    }
}

// Push the top element from stack B to stack A
void pa(t_list **stack_a, t_list **stack_b)
{
    if (*stack_b)
    {
        t_list *temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = *stack_a;
        *stack_a = temp;
        write(1, "pa\n", 3);
    }
}

// Rotate the stack up by 1
void ra(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *first;
        t_list *last;

        first = *stack;
        last = ft_lstlast(*stack);
        *stack = (*stack)->next;
        last->next = first;
        first->next = NULL;
        write(1, "ra\n", 3);
    }
}

// Reverse rotate the stack down by 1
void rra(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *second_last;
        t_list *last;

        second_last = NULL;
        last = *stack;
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }
        second_last->next = NULL;
        last->next = *stack;
        *stack = last;
        write(1, "rra\n", 4);
    }
}

// Swap the first two elements in the stack
void sa(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (*stack && (*stack)->next)
    {
        first = *stack;
        second = (*stack)->next;
        first->next = second->next;
        second->next = first;
        *stack = second;
        write(1, "sa\n", 3);
    }
}
