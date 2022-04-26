#include "../includes/push_swap.h"
#include "../includes/heap.h"
#include <stdio.h>
#include <unistd.h>

#define CHUNK_SIZE 50

static int		is_ascending(t_deque *deque, int size)
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

static int	find_index(t_deque *deque, int data)
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

void	push_swap_under3(t_deque *a, t_deque *b, t_heap *heap)
{
	int	min;
	int	ra_count;
	int	rra_count;
	int	i;

	ra_count = 0;
	rra_count = 0;
	i = 0;
	min = heap_delete(heap);
	while (a->head->data != min)
	{
		i = find_index(a, min);
		if (i <= a->size / 2)
		{
			rotate(a);
			++ra_count;
			//printf("ra\n");
		}
		else
		{
			reverse_rotate(a);
			++rra_count;
			//printf("rra\n");
		}
	}
	if (!is_ascending(a, a->size))
	{
		++ra_count;
		++rra_count;
		while (--ra_count)
			reverse_rotate(a);
		while (--rra_count)
			rotate(a);
		swap(a);
		printf("sa\n");
		while (a->head->data != min)
		{
			i = find_index(a, min);
			if (i <= a->size / 2)
			{
				rotate(a);
				printf("ra\n");
			}
			else
			{
				reverse_rotate(a);
				printf("rra\n");
			}
		}
	}
	if (ra_count)
	{
		rotate(a);
		printf("ra\n");
	}
	if (rra_count)
	{
		reverse_rotate(a);
		printf("rra\n");
	}
	while (b->size)
	{
		push(b, a);
		printf("pa\n");
	}
	exit(0);
}

void	push_swap_init(t_deque *a, t_deque *b)
{
	t_node	*cur;
	int		size;
	t_heap	heap;
	int		min;
	int		i;
	int		ra_count;
	int		rra_count;

	size = CHUNK_SIZE;
	if (a->size < 200)
		size = 25;
	if (a->size < size)
		size = a->size;
	heap_initialize(&heap, size);
	cur = a->head;
	i = 0;
	ra_count = 0;
	rra_count = 0;
	while (i < size)
	{
		heap_insert(&heap, cur->data);
		cur = cur->next;
		++i;
	}
	while (heap.size > 3)
	{
		if (is_ascending(a, a->size) && b->size == 0)
			exit (0);
		min = heap_delete(&heap);
		while (a->head->data != min)
		{
			i = find_index(a, min);
			if (i < a->size / 2)
			{
				rotate(a);
				write(1, "ra\n", 3);
			}
			else
			{
				reverse_rotate(a);
				write(1, "rra\n", 4);
			}
			if (is_ascending(a, a->size) && b->size == 0)
				exit (0);
		}
		push(a, b);
		write(1, "pb\n", 3);
	}
	if (a->size == 3)
		push_swap_under3(a, b, &heap);
	while (heap.size)
	{
		if (is_ascending(a, a->size) && b->size == 0)
			exit (0);
		min = heap_delete(&heap);
		while (a->head->data != min)
		{
			i = find_index(a, min);
			if (i < a->size / 2)
			{
				rotate(a);
				write(1, "ra\n", 3);
			}
			else
			{
				reverse_rotate(a);
				write(1, "rra\n", 4);
			}
			if (is_ascending(a, a->size) && b->size == 0)
				exit (0);
		}
		push(a, b);
		write(1, "pb\n", 3);
	}
}
