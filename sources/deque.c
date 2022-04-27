/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:34:14 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:34:21 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	return (new_node);
}

void	init_deque(t_deque *deque)
{
	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
}

int	is_empty(t_deque *deque)
{
	if (deque->size == 0)
		return (1);
	return (0);
}

void	add_front(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		terminate();
	new_node->next = deque->head;
	if (is_empty(deque))
		deque->tail = new_node;
	else
		deque->head->prev = new_node;
	deque->head = new_node;
	++deque->size;
}

void	add_rear(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		terminate();
	new_node->prev = deque->tail;
	if (is_empty(deque))
		deque->head = new_node;
	else
		deque->tail->next = new_node;
	deque->tail = new_node;
	++deque->size;
}

int	delete_front(t_deque *deque)
{
	t_node	*removed_node;
	int		data;

	removed_node = deque->head;
	if (is_empty(deque))
		terminate();
	data = deque->head->data;
	deque->head = deque->head->next;
	free(removed_node);
	--deque->size;
	if (deque->head == NULL)
		deque->tail = NULL;
	else
		deque->head->prev = NULL;
	return (data);
}

int	delete_rear(t_deque *deque)
{
	t_node	*removed_node;
	int		data;

	removed_node = deque->tail;
	if (is_empty(deque))
		terminate();
	data = deque->tail->data;
	deque->tail = deque->tail->prev;
	free(removed_node);
	--deque->size;
	if (deque->tail == NULL)
		deque->head = NULL;
	else
		deque->tail->next = NULL;
	return (data);
}

int	get_front(t_deque *deque)
{
	if (is_empty(deque))
		terminate();
	return (deque->head->data);
}

int	get_rear(t_deque *deque)
{
	if (is_empty(deque))
		terminate();
	return (deque->tail->data);
}
