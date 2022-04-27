/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:35:28 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:35:29 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/deque.h"

void	swap(t_deque *deque)
{
	int	tmp;

	if (deque->size > 1)
	{
		tmp = deque->head->data;
		deque->head->data = deque->head->next->data;
		deque->head->next->data = tmp;
	}
}

void	push(t_deque *deque_from, t_deque *deque_to)
{
	int	data;

	if (deque_from->size > 0)
	{
		data = delete_front(deque_from);
		add_front(deque_to, data);
	}
}

void	rotate(t_deque *deque)
{
	int	data;

	if (deque->size > 1)
	{
		data = delete_front(deque);
		add_rear(deque, data);
	}
}

void	reverse_rotate(t_deque *deque)
{
	int	data;

	if (deque->size > 1)
	{
		data = delete_rear(deque);
		add_front(deque, data);
	}
}
