/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:42:25 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:42:56 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_deque;

t_node	*create_node(int data);
void	init_deque(t_deque *deque);
int		is_empty(t_deque *deque);
void	add_rear(t_deque *deque, int item);
void	add_front(t_deque *deque, int item);
int		delete_front(t_deque *deque);
int		delete_rear(t_deque *deque);
int		get_front(t_deque *deque);
int		get_rear(t_deque *deque);

#endif
