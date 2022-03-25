#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	ss(t_deque *a, t_deque *b)
{
	swap(a);
	swap(b);
}

void	rr(t_deque *a, t_deque *b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_deque *a, t_deque *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
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
	{	
		add_rear(&a, atoi(argv[i]));
	}
	print(&a, &b);
	while (1)
	{
		char string[4] = {0,};
		scanf("%s", string);
		int	command = string[0] + string[1] + string[2] + string[3];

		if (command == 'r' + 'a')
			rotate(&a);
		else if (command == 'r' + 'b')
		{
			if (string[1] == 'b')
				rotate(&b);
			else
				swap(&a);
		}
		else if (command == 'r' + 'r')
			rr(&a, &b);
		else if (command == 'r' + 'r' + 'a')
			reverse_rotate(&a);
		else if (command == 'r' + 'r' + 'b')
			reverse_rotate(&b);
		else if (command == 'r' + 'r' + 'r')
			rrr(&a, &b);
		else if (command == 'p' + 'a')
			push(&b, &a);
		else if (command == 'p' + 'b')
			push(&a, &b);
		else if (command == 's' + 'b')
			swap(&b);
		else if (command == 's' + 's')
			ss(&a, &b);
		print(&a, &b);
	}
	return (0);
}
