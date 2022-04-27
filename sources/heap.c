/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:17:56 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:34:39 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/heap.h"
#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	swap_pc(int *p, int *c)
{
	int	tmp;

	tmp = *p;
	*p = *c;
	*c = tmp;
}

void	heap_initialize(t_heap *heap, int size)
{
	heap->array = (int *)ft_calloc(size + 1, sizeof(int));
	if (!heap->array)
		terminate();
	heap->size = 0;
	heap->max_size = size + 1;
}

void	heap_insert(t_heap *heap, int item)
{
	int	index;

	heap->size += 1;
	index = heap->size;
	if (index > heap->max_size)
		terminate();
	while (index != 1 && item < heap->array[index / 2])
	{
		heap->array[index] = heap->array[index / 2];
		index /= 2;
	}
	heap->array[index] = item;
}

int	heap_delete(t_heap *heap)
{
	int	root;
	int	parent;
	int	child;

	root = 0;
	parent = 1;
	if (heap->size == 0)
		terminate();
	root = heap->array[1];
	heap->array[1] = heap->array[heap->size];
	--heap->size;
	while (1)
	{
		child = parent * 2;
		if ((child + 1 <= heap->size) && \
				(heap->array[child] > heap->array[child + 1]))
			++child;
		if ((child > heap->size) || \
				(heap->array[child] > heap->array[parent]))
			break ;
		swap_pc(&heap->array[parent], &heap->array[child]);
		parent = child;
	}
	return (root);
}
