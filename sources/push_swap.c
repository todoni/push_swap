#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include <unistd.h>
#define CHUNK_SIZE 50


void	minval_to_top(t_deque *a, int min, t_count *count)
{
	int	index;

	count->ra = 0;
	count->rra = 0;
	while (a->head->data != min)
	{
		index = find_index(a, min);
		if (index < a->size / 2)
		{
			rotate(a);
			++count->ra;
		}
		else
		{
			reverse_rotate(a);
			++count->rra;
		}
	}
}

void	print_rotation_valid(t_count *count, int size_b)
{
	int	valid_rotation;

	valid_rotation = count->rrb - count->rb;
	if (valid_rotation < 0)
	{
		valid_rotation = size_b + valid_rotation + 1;
		while (--valid_rotation)
			write(1, "rrb\n", 4);
	}
	else if (valid_rotation > 0)
	{
		++valid_rotation;
		while (--valid_rotation)
		{
			if (count->rra)
			{
				write(1, "rrr\n", 4);
				--count->rra;
			}
			else
				write(1, "rrb\n", 4);
		}
	}
}

void	print_rotation_remain(t_count *count)
{
	while (count->ra)
	{
		write(1, "ra\n", 3);
			--count->ra;
	}
	while (count->rra)
	{
		write(1, "rra\n", 4);
			--count->rra;
	}
}

void	make_b_descending(t_deque *b, t_count *count)
{
	int	i;

	i = 0;
	count->rb = 0;
	while (i < count->rrb + 1)
	{
		rotate(b);
		++i;
		++count->rb;
	}
}

void	init_count(t_count *count)
{
	count->rrb = 0;
	count->rb = 0;
	count->ra = 0;
	count->rra = 0;
}

void	next_minval_to_top(t_deque *b, int min, t_count *count)
{
	count->rrb = 0;
	while (min > get_rear(b) && count->rrb < b->size)
	{
		reverse_rotate(b);
		++count->rrb;
	}
}

void	make_a_ascending(int count)
{
	while (--count)
		write(1, "ra\n", 3);
}

void	push_swap(t_deque *a, t_deque *b)
{
	t_count	count;
	int	size;
	t_heap	heap;
	int	min;

	init_count(&count);
	size = CHUNK_SIZE;
	if (a->size < 200)
		size = 25;
	while (a->size)
	{
		make_heap(&heap, a, size);
		while (heap.size)
		{
			min = heap_delete(&heap);
			minval_to_top(a, min, &count);
			next_minval_to_top(b, min, &count);
			print_rotation_valid(&count, b->size);
			print_rotation_remain(&count);
			push(a, b);
			write(1, "pb\n", 3);
			make_b_descending(b, &count);
		}
	}
	while (b->size)
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
	make_a_ascending(a->size - count.rb + 1);
}
