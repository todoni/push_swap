#include "../includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void SortStack(t_deque *orig_stack, t_deque *helper_stack)
{
  //t_deque helper_stack;
  while (orig_stack->size)
  {
    int element = get_front(orig_stack);
    while (helper_stack->size && get_front(helper_stack) < element)
    {
      push(helper_stack, orig_stack);
    }
    push(orig_stack, helper_stack);
  }
  while (helper_stack->size)
  {
    push(helper_stack, orig_stack);
  }
}

void	print(t_deque *a, t_deque *b)
{
	t_node	*cur_a;
	t_node	*cur_b;

	cur_a = a->head;
	cur_b = b->head;
	while (cur_a || cur_b)
	{
		if (cur_a)
		{	
			printf("%d", cur_a->data);
			cur_a = cur_a->next;
		}
		else
			printf(" ");
		printf(" ");
		if (cur_b)
		{
			printf("%d", cur_b->data);
			cur_b = cur_b->next;
		}
		else
			printf(" ");
		printf("\n");
	}
	printf("- -\na b\n\n");
}

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;
	int		i = 0;

	init_deque(&a);
	init_deque(&b);
	while (argv[++i])
		add_rear(&a, atoi(argv[i]));
	print(&a, &b);
	SortStack(&a, &b);
	print(&a, &b);
}
