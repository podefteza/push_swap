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

void sb(t_list **stack)
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
        write(1, "sb\n", 3);
    }
}

// Swap the first two elements in both stacks A and B
void ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    write(1, "ss\n", 3);
}

// Rotate the stack B up by 1
void rb(t_list **stack)
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
        write(1, "rb\n", 3);
    }
}

// Rotate both stacks A and B up by 1
void rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);
}

// Reverse rotate the stack B down by 1
void rrb(t_list **stack)
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
        write(1, "rrb\n", 4);
    }
}

// Reverse rotate both stacks A and B down by 1
void rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1, "rrr\n", 4);
}
