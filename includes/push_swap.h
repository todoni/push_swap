#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"

void	swap(t_deque *deque);
void	push(t_deque *deque_from, t_deque *deque_to);
void	rotate(t_deque *deque);
void	reverse_rotate(t_deque *deque);

#endif
