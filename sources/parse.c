/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:35:42 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:35:44 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include "../includes/heap.h"
#include "../includes/deque.h"

static int	find_digit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		digit = 1;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

void	make_stack_a(int argc, char **argv, t_deque *a)
{
	char	*buf;
	int		argument;
	int		argument_length;
	int		index;

	index = 1;
	while (index < argc)
	{
		buf = argv[index];
		while (*buf)
		{
			argument = atoi_safe(buf);
			argument_length = find_digit(argument);
			while (ft_isspace(*buf))
				++buf;
			if (*buf == '-' || *buf == '+')
				++buf;
			add_rear(a, argument);
			buf += argument_length;
		}
		++index;
	}
}

void	check_argument_duplicate(t_deque *a)
{
	t_node	*cur;
	t_heap	buf;
	int		num;
	int		num_next;

	heap_initialize(&buf, a->size);
	cur = a->head;
	while (cur)
	{
		heap_insert(&buf, cur->data);
		cur = cur->next;
	}
	num = heap_delete(&buf);
	while (buf.size)
	{
		num_next = heap_delete(&buf);
		if (num == num_next)
			terminate();
		num = num_next;
	}
	free(buf.array);
}

int	is_argument_valid(int argc, char **argv)
{
	char	*buf;

	while (--argc)
	{
		buf = argv[argc];
		while (*buf)
		{
			if (!ft_isdigit(*buf) && !ft_isspace(*buf) \
					&& *buf != '-' && *buf != '+')
				return (0);
			++buf;
		}
	}
	return (1);
}
