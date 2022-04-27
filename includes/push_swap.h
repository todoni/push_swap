/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:36:36 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:37:30 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"
# include "heap.h"
# include <unistd.h>

typedef struct s_count
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
}	t_count;

void	swap(t_deque *deque);
void	push(t_deque *deque_from, t_deque *deque_to);
void	rotate(t_deque *deque);
void	reverse_rotate(t_deque *deque);
void	terminate(void);
void	print_instruction(const char *instruction);
int		is_argument_valid(int argc, char **argv);
void	check_argument_duplicate(t_deque *a);
void	make_stack_a(int argc, char **argv, t_deque *a);
void	push_swap_init(t_deque *a, t_deque *b);
int		atoi_safe(const char *str);
int		find_index(t_deque *deque, int data);
int		is_ascending(t_deque *deque);
void	push_swap(t_deque *a, t_deque *b);
void	make_heap(t_heap *heap, t_deque *deque, int size);

#endif
