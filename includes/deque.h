#ifndef DEQUE_H
# define DEQUE_H

typedef int element;

typedef struct	s_node{
    element		data;
    struct s_node	*prev;
    struct s_node 	*next;
}	t_node;

typedef struct	s_deque{
    t_node	*head;
    t_node	*tail;
    int		size;
}	t_deque;

t_node	*create_node(element data);
void	init_deque(t_deque *deque);
int		is_empty(t_deque *deque);
int		is_full(t_deque *deque);
void	add_rear(t_deque *deque, element item);
void	add_front(t_deque *deque, element item);
element	delete_front(t_deque *deque);
element	delete_rear(t_deque *deque);
element	get_front(t_deque *deque);
element	get_rear(t_deque *deque);


#endif
