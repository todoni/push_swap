#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../includes/heap.h"
#include <stdio.h>
#define CHUNK_SIZE 50

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

int		is_ascending(t_deque *deque, int size)
{
	int		i;
	t_node	*node;

	i = 0;
	node = deque->head;
	while (++i < size)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int		is_descending(t_deque *deque, int size)
{
	int		i;
	t_node	*node;

	i = 0;
	node = deque->head;
	while (++i < size)
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
	int		size;
	t_node	*cur;

	i = 0;
	cur = deque->head;
	size = CHUNK_SIZE;
	if (deque->size < CHUNK_SIZE)
		size = deque->size;
	while (cur->data != data)
	{
		++i;
		cur = cur->next;
	}
	return (i);
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
	//int		*arr_int;
	//int		count;
	int		i;
	t_deque	a;
	t_deque	b;
	t_heap	heap;
	int	min;
	int	index;
	int	size;

	if (!is_argument_valid(argc, argv))
		terminate();
	make_stack_a(argc, argv, &a);
	check_argument_duplicate(&a);
	//count = argc - 1;
	i = 0;
	index = 0;
	//init_deque(&a);
	init_deque(&b);
	heap_initialize(&heap, CHUNK_SIZE);
	//arr_int = (int *)ft_calloc(count, sizeof(int));
	//printf("size:%d a:", count);
	/*while (i < count)
	{
		arr_int[i] = ft_atoi(argv[i + 1]);
		add_rear(&a, arr_int[i]);
		printf("%d ", arr_int[i]);
		++i;
	}
	printf("\n");*/
	t_node	*cur;
	size = CHUNK_SIZE;
	if (a.size < 200)
		size = 25;
	if (a.size < size)
		size = a.size;
	heap_initialize(&heap, size);
	cur = a.head;
	i = 0;
	while (i < size)
	{
		heap_insert(&heap, cur->data);
		cur = cur->next;
		++i;
	}
	while (heap.size)
	{
		if (is_ascending(&a, a.size) && b.size == 0)
			exit (0);
		min = heap_delete(&heap);
		while (a.head->data != min)
		{
			i = find_index(&a, min);
			if (i < a.size / 2 )
			{	
				rotate(&a);
				printf("ra\n");
			}
			else
			{
				reverse_rotate(&a);
				printf("rra\n");
			}
			if (is_ascending(&a, a.size) && b.size == 0)
				exit (0);
		}
		push(&a, &b);
		printf("pb\n");
	}
	int	rrb_count;
	int	rb_count;
	int	ra_count;
	int	rra_count;
	int	j;
	int	check;

	rrb_count = 0;
	rb_count = 0;
	ra_count = 0;
	rra_count = 0;
	j = 0;
	check = 0;
	while (a.size)
	{
		if (a.size < size)
			size = a.size;
		heap_initialize(&heap, size);
		i = 0;
		cur = a.head;
		while (i < size)
		{
			heap_insert(&heap, cur->data);
			cur = cur->next;
			++i;
		}
		while (heap.size)
		{
			min = heap_delete(&heap);
			ra_count = 0;
			rra_count = 0;
			while (a.head->data != min)
			{
				i = find_index(&a, min);
				if (i < a.size / 2)
				{	
					rotate(&a);
					++ra_count;
				}
				else
				{
					reverse_rotate(&a);
					++rra_count;
				}
			}
			rrb_count = 0;
			while (get_front(&a) > get_rear(&b) && rrb_count < b.size)
			{
				reverse_rotate(&b);
				++rrb_count;
			}
			check = rrb_count - rb_count;
			if (rrb_count == b.size + 1)
				check = 0;
			if (check < 0)
			{
				check = b.size + check + 1;
				while (--check)
				{
					printf("rrb\n");
				}
			}
			else if (check > 0)
			{
				++check;
				while (--check)
				{
					if (rra_count > 0)
					{
						printf("rrr\n");
						--rra_count;
					}
					else
						printf("rrb\n");
				}
			}
			while (ra_count > 0)
			{
				printf("ra\n");
				--ra_count;
			}
			while (rra_count > 0)
			{
				printf("rra\n");
				--rra_count;
			}
			push(&a, &b);
			printf("pb\n");
			j = 0;
			rb_count = 0;
			while (j < rrb_count + 1)
			{
				rotate(&b);
				++j;
				++rb_count;
			}
		}
	}
	while (b.size)
	{
		push(&b, &a);
		printf("pa\n");
	}
	check = a.size - rb_count + 1;
	while (--check)
		printf("ra\n");
}
