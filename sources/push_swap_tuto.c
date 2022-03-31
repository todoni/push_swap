#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../includes/heap.h"
#include <stdio.h>
#define CHUNK_SIZE 8

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
		//if (cur->data == data)
		//	break;
		++i;
		cur = cur->next;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	//char	**numbers;
	int		*arr_int;
	//int		*arr_chunk;
	int		count;
	int		i;
	t_deque	a;
	t_deque	b;
	t_deque	a_copy;
	t_deque	b_copy;
	//t_deque	chunk;
	t_heap	heap;
	int		min;
	int		index;
	//int		val;

	count = argc - 1;
	i = 0;
	index = 0;
	init_deque(&a);
	init_deque(&b);
	init_deque(&a_copy);
	init_deque(&b_copy);
	heap_initialize(&heap, CHUNK_SIZE);
	//numbers = (char **)ft_calloc(count, sizeof(char *));
	arr_int = (int *)ft_calloc(count, sizeof(int));
	while (i < count)
	{
		//numbers[i] = argv[i + 1];
		arr_int[i] = ft_atoi(argv[i + 1]);
		add_rear(&a, arr_int[i]);
		add_rear(&a_copy, arr_int[i]);
		++i;
	}
	/*while (index < CHUNK_SIZE)
	{	
		heap_insert(&heap, arr_int[index]);
		++index;
	}*/
	//print(&a, &b);
	//printf("\n");
	i = 0;
	/*if (is_ascending(&a))
	{
		while (i < CHUNK_SIZE)
		{
			push(&a, &b);
			printf("pb\n");
			++i;
		}
	}*/
	//print(&a, &b);
	//exit(0);
	/*if (is_descending(&a))
	{
		while (--a.size)
		{		rotate(&a);
			print(&a, &b);}
		return (0);
	}*/
	//printf("%d\n", min);
	int	size;
	t_node	*cur;
	size = CHUNK_SIZE;
		if (a.size < CHUNK_SIZE)
			size = a.size;
		//arr_chunk = (int *)ft_calloc(size, sizeof(int));
		//init_deque(&chunk);
		heap_initialize(&heap, size);
		i = 0;
		cur = a.head;
		while (i < size)
		{
			//arr_chunk[i] = delete_front(&a);
			//add_rear(&chunk, arr_chunk[i]);
			heap_insert(&heap, cur->data);
			cur = cur->next;
			++i;
		}
		while (heap.size)
		{
			/*if (is_ascending(&a, heap.size))
			{
				i = 0;
				while (i < heap.size)
				{
					push(&a, &b);
					printf("pb\n");
					++i;
					//val

				}
				heap.size = 0;
			}*/
			//else
			//{
				min = heap_delete(&heap);
				//i = find_index(&a, min);
				while (a.head->data != min)
				{
					i = find_index(&a, min);
					if (i < a.size / 2 )
					{	
						rotate(&a);
						rotate(&a_copy);
						printf("ra\n");
						//--i;
					}
					else
					{
						reverse_rotate(&a);
						reverse_rotate(&a_copy);
						printf("rra\n");
						//++i;
					}
					//--i;
				}
				push(&a, &b);
				push(&a_copy, &b_copy);
				printf("pb\n");
		//	}
			//++j;
		}
		printf("init----------------\n");
		//print(&a, &b);
	int	rrb_count;
	int	rb_count;
	int	j;
	int	check;

	rrb_count = 0;
	rb_count = 0;
	j = 0;
	check = 0;
	while (a.size)
	{
		size = CHUNK_SIZE;
		if (a.size < CHUNK_SIZE)
			size = a.size;
		//arr_chunk = (int *)ft_calloc(size, sizeof(int));
		//init_deque(&chunk);
		heap_initialize(&heap, size);
		i = 0;
		cur = a.head;
		while (i < size)
		{
			//arr_chunk[i] = delete_front(&a);
			//add_rear(&chunk, arr_chunk[i]);
			heap_insert(&heap, cur->data);
			cur = cur->next;
			++i;
		}
		while (heap.size)
		{
			/*if (is_ascending(&a, heap.size))
			{
				i = 0;
				while (i < heap.size)
				{
					rrb_count = 0;
					while (get_front(&a) > get_rear(&b))
					{	
						reverse_rotate(&b);
						printf("rrb\n");
						++rrb_count;
						print(&a, &b);
					}
					push(&a, &b);
					printf("pb\n");
					print(&a, &b);
					j = 0;
					while (++j < rrb_count)
					{
						rotate(&b);
						printf("rb\n");
						print(&a, &b);
						//++j;
					}
					++i;
					//val

				}
				heap.size = 0;
			}*/
			//else
			//{
				min = heap_delete(&heap);
				//i = find_index(&a, min);
				while (a.head->data != min)
				{
					i = find_index(&a, min);
					if (i < a.size / 2)
					{	
						rotate(&a);
						rotate(&a_copy);
						printf("ra\n");
						//--i;
					}
					else
					{
						reverse_rotate(&a);
						reverse_rotate(&a_copy);
						printf("rra\n");
						//++i;
					}
					//--i;
				}
				rrb_count = 0;
				while (get_front(&a) > get_rear(&b) && rrb_count < b.size)
					{	
						reverse_rotate(&b);
						//printf("rrb\n");
						//print(&a, &b);
						++rrb_count;
					}
				check = rrb_count - rb_count;
				if (rrb_count == b.size + 1)
					check = 0;
				if (check < 0)
				{
					--check;
					while (++check)
					{
						rotate(&b_copy);
						printf("rb\n");
					}
				}
				else if (check > 0)
				{
					++check;
					while (--check)
					{
						reverse_rotate(&b_copy);
						printf("rrb\n");
					}
				}
					push(&a, &b);
					push(&a_copy, &b_copy);
					printf("pb\n");
					//print(&a, &b);
					j = 0;
					rb_count = 0;
					while (j < rrb_count + 1)
					{
						rotate(&b);
						//printf("rb\n");
						//print(&a, &b);
						++j;
						++rb_count;
					}

				//push(&a, &b);
				//printf("pb\n");
			//}
			//++j;
		}
		//printf("----------------\n");
	}
	//print(&a, &b);
	//exit(0);
	while (b.size)
	{
		push(&b, &a);
		//printf("pa\n");
	}
	//printf("\n");
	//print(&a, &b);
	//print(&a_copy, &b_copy);
}
