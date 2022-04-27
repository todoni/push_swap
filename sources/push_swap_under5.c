/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:35:11 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:35:12 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <unistd.h>
#define CHUNK_SIZE 50

static void	rotate_sort(t_deque *a, int min, int *rotation)
{
	int	index;

	if (a->head->data != min)
	{
		index = find_index(a, min);
		if (index <= a->size / 2)
		{
			rotate(a);
			*rotation |= 1;
		}
		else
		{
			reverse_rotate(a);
			*rotation |= 2;
		}
	}
}

static void	swap_sort(t_deque *a, int min, int *rotation)
{
	int	index;

	if (*rotation & 1)
		reverse_rotate(a);
	if (*rotation & 2)
		rotate(a);
	*rotation &= ~3;
	swap(a);
	print_instruction("sa\n");
	if (a->head->data != min)
	{
		index = find_index(a, min);
		if (index <= a->size / 2)
			print_instruction("ra\n");
		else
			print_instruction("rra\n");
	}
}

void	push_swap_under3(t_deque *a, t_deque *b, t_heap *heap)
{
	int	min;
	int	rotation;

	rotation = 0;
	min = heap_delete(heap);
	rotate_sort(a, min, &rotation);
	if (!is_ascending(a))
		swap_sort(a, min, &rotation);
	if (rotation & 1)
		print_instruction("ra\n");
	if (rotation & 2)
		print_instruction("rra\n");
	while (b->size)
	{
		push(b, a);
		print_instruction("pa\n");
	}
	exit(0);
}

void	push_sort(t_deque *a, t_deque *b, t_heap *heap)
{
	int	min;
	int	index;

	min = heap_delete(heap);
	while (a->head->data != min)
	{
		index = find_index(a, min);
		if (index < a->size / 2)
		{
			rotate(a);
			print_instruction("ra\n");
		}
		else
		{
			reverse_rotate(a);
			print_instruction("rra\n");
		}
	}
	if (is_ascending(a) && b->size == 0)
		exit (0);
	push(a, b);
	print_instruction("pb\n");
}

void	make_heap(t_heap *heap, t_deque *deque, int size)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = deque->head;
	if (deque->size < size)
		size = deque->size;
	heap_initialize(heap, size);
	while (i < size)
	{
		heap_insert(heap, cur->data);
		cur = cur->next;
		++i;
	}
}

void	push_swap_init(t_deque *a, t_deque *b)
{
	int		size;
	t_heap	heap;

	size = CHUNK_SIZE;
	if (a->size < 200)
		size = 25;
	make_heap(&heap, a, size);
	while (heap.size > 3)
		push_sort(a, b, &heap);
	if (a->size == 3)
		push_swap_under3(a, b, &heap);
	while (heap.size)
		push_sort(a, b, &heap);
	free(heap.array);
}
