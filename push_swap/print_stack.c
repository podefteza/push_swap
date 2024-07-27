/* TEST... DELETE LATER... */

#include "push_swap.h"

void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%d\n", *(int *)(stack->content));
        stack = stack->next;
    }
}
