/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tuto.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:35:00 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:35:04 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../includes/heap.h"
#include <unistd.h>
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

int	is_ascending(t_deque *deque)
{
	int		i;
	t_node	*node;

	i = 0;
	node = deque->head;
	while (++i < deque->size)
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
	t_node	*cur;

	i = 0;
	cur = deque->head;
	if (!cur)
		return (-1);
	while (cur->data != data)
	{
		++i;
		cur = cur->next;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;

	if (!is_argument_valid(argc, argv))
		terminate();
	init_deque(&a);
	init_deque(&b);
	make_stack_a(argc, argv, &a);
	check_argument_duplicate(&a);
	if (is_ascending(&a))
		exit(0);
	push_swap_init(&a, &b);
	push_swap(&a, &b);
	return (0);
}
