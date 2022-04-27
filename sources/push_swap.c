/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:34:52 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:34:54 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			print_instruction("rrb\n");
	}
	else if (valid_rotation > 0)
	{
		++valid_rotation;
		while (--valid_rotation)
		{
			if (count->rra)
			{
				print_instruction("rrr\n");
				--count->rra;
			}
			else
				print_instruction("rrb\n");
		}
	}
}

void	print_rotation_remain(t_count *count)
{
	while (count->ra)
	{
		print_instruction("ra\n");
			--count->ra;
	}
	while (count->rra)
	{
		print_instruction("rra\n");
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
		print_instruction("ra\n");
}

static void	push_sort(t_deque *a, t_deque *b, int min, t_count *count)
{
	minval_to_top(a, min, count);
	next_minval_to_top(b, min, count);
	print_rotation_valid(count, b->size);
	print_rotation_remain(count);
	push(a, b);
	print_instruction("pb\n");
	make_b_descending(b, count);
}

void	push_swap(t_deque *a, t_deque *b)
{
	t_count	count;
	t_heap	heap;
	int		size;
	int		min;

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
			push_sort(a, b, min, &count);
		}
		free(heap.array);
	}
	while (b->size)
	{
		push(b, a);
		print_instruction("pa\n");
	}
	make_a_ascending(a->size - count.rb + 1);
}
