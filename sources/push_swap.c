#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../includes/heap.h"
#include <unistd.h>
#define CHUNK_SIZE 50

void	push_swap(t_deque *a, t_deque *b)
{
	int	rrb_count;
	int	rb_count;
	int	ra_count;
	int	rra_count;
	int	j;
	int	check;
	int	size;
	int	i;
	t_heap	heap;
	t_node	*cur;
	int		min;

	rrb_count = 0;
	rb_count = 0;
	ra_count = 0;
	rra_count = 0;
	j = 0;
	check = 0;
	size = CHUNK_SIZE;
	if (a->size < 200)
		size = 25;
	if (a->size < size)
		size = a->size;
	while (a->size)
	{
		if (a->size < size)
			size = a->size;
		heap_initialize(&heap, size);
		i = 0;
		cur = a->head;
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
			while (a->head->data != min)
			{
				i = find_index(a, min);
				if (i < a->size / 2)
				{	
					rotate(a);
					++ra_count;
				}
				else
				{
					reverse_rotate(a);
					++rra_count;
				}
			}
			rrb_count = 0;
			while (get_front(a) > get_rear(b) && rrb_count < b->size)
			{
				reverse_rotate(b);
				++rrb_count;
			}
			check = rrb_count - rb_count;
			if (rrb_count == b->size + 1)
				check = 0;
			if (check < 0)
			{
				check = b->size + check + 1;
				while (--check)
				{
					write(1, "rrb\n", 4);
				}
			}
			else if (check > 0)
			{
				++check;
				while (--check)
				{
					if (rra_count > 0)
					{
						write(1, "rrr\n", 4);
						--rra_count;
					}
					else
						write(1, "rrb\n", 4);
				}
			}
			while (ra_count > 0)
			{
				write(1, "ra\n", 3);
				--ra_count;
			}
			while (rra_count > 0)
			{
				write(1, "rra\n", 4);
				--rra_count;
			}
			push(a, b);
			write(1, "pb\n", 3);
			j = 0;
			rb_count = 0;
			while (j < rrb_count + 1)
			{
				rotate(b);
				++j;
				++rb_count;
			}
		}
	}
	while (b->size)
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
	//print(a, b);
	check = a->size - rb_count + 1;
	while (--check)
		write(1, "ra\n", 3);
	//print(a, b);
}
