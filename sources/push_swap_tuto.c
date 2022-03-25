#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../includes/heap.h"
#include <stdio.h>

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
	printf("- -\na b\n");
}

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

int		is_ascending(t_deque *deq)
{
	int		i;
	t_node	*node;

	i = 0;
	node = deq->head;
	while (++i < deq->size)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int		is_descending(t_deque *deq)
{
	int		i;
	t_node	*node;

	i = 0;
	node = deq->head;
	while (++i < deq->size)
	{
		if (node->data < node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	find_index(t_deque *deque, int data)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = deque->head;
	while (cur)
	{
		if (cur->data == data)
			break;
		++i;
		cur = cur->next;
	}
	return (i);
}



int	main(int argc, char **argv)
{
	//char	**numbers;
	int		*arr_int;
	int		count;
	int		i;
	t_deque	a;
	t_deque	b;
	t_heap	heap;
	int		min;

	count = argc - 1;
	i = 0;
	init_deque(&a);
	init_deque(&b);
	heap_initialize(&heap, count);
	//numbers = (char **)ft_calloc(count, sizeof(char *));
	arr_int = (int *)ft_calloc(count, sizeof(int));
	while (i < count)
	{
		//numbers[i] = argv[i + 1];
		arr_int[i] = ft_atoi(argv[i + 1]);
		add_rear(&a, arr_int[i]);
		heap_insert(&heap, arr_int[i]);
		++i;
	}
	//print(&a, &b);
	//printf("\n");
	if (is_ascending(&a))
		return (0);
	/*if (is_descending(&a))
	{
		while (--a.size)
		{		rotate(&a);
			print(&a, &b);}
		return (0);
	}*/
	//printf("%d\n", min);
	while (!is_ascending(&a))
	{
		min = heap_delete(&heap);
		i = find_index(&a, min);
		//printf("a stack size:%d\n", a.size);
		while (a.head->data != min)
		{
			/*if (i == 1)
			{
				swap(&a);
				printf("sa\n");
				break;
			}*/
			if (i <= a.size / 2 )
			{	
				rotate(&a);
				printf("ra\n");
			}
			else
			{
				reverse_rotate(&a);
				printf("rra\n");
			}
		}
		
		if (is_ascending(&a))
			break ;
		//print(&a, &b);
		push(&a, &b);
		printf("pb\n");
		//print(&a, &b);
	}
	while (b.size)
	{
		push(&b, &a);
		printf("pa\n");
	}
	//printf("\n");
	//print(&a, &b);
}
