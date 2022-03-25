#include "../includes/deque.h"
#include "../libft/libft.h"
#include <stdio.h>

t_node	*create_node(element data)
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

void	add_front(t_deque *deque, element data)
{ 
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		exit(1);
	new_node->next = deque->head;
	if (is_empty(deque)) 
		deque->tail= new_node;
	else
		deque->head->prev = new_node;
	deque->head = new_node;
	++deque->size;
}

void	add_rear(t_deque *deque, element data)
{
	t_node *new_node;

	new_node = create_node(data);
	if (!new_node)
		exit(1);
	new_node->prev = deque->tail;
	if (is_empty(deque))
		deque->head = new_node;
	else
		deque->tail->next = new_node;
	deque->tail = new_node;
	++deque->size;
}

element delete_front(t_deque *deque)
{
	t_node	*removed_node;
	element	data;

	removed_node = deque->head;
	if (is_empty(deque))
	{
		printf("empty deque.\n");
		return (-1);
	}
	data = deque->head->data;
	deque->head = deque->head->next;
	free(removed_node);
	--deque->size;
	//if (deque->head == NULL)
	if (deque->size == 0)
		deque->tail = NULL;
	else
		deque->head->prev = NULL;
	return (data);
}

element delete_rear(t_deque *deque)
{
	t_node	*removed_node;
	element	data;

	removed_node = deque->tail;
	if (is_empty(deque))
	{
		printf("empty deque.\n");
		return (-1);
	}
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

element	get_front(t_deque *deque)
{
	if (is_empty(deque))
	{
		printf("empty deque.\n");
		return (-1);
	}
	return (deque->head->data);
}

element	get_rear(t_deque *deque)
{
	if (is_empty(deque))
	{
		printf("empty deque.\n");
		return (-1);
	}
	return (deque->tail->data);
}
