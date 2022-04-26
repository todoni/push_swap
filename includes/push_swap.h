#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"

void	swap(t_deque *deque);
void	push(t_deque *deque_from, t_deque *deque_to);
void	rotate(t_deque *deque);
void	reverse_rotate(t_deque *deque);
void	terminate(void);
int		is_argument_valid(int argc, char **argv);
void	check_argument_duplicate(t_deque *a);
void	make_stack_a(int argc, char **argv, t_deque *a);
void	push_swap_init(t_deque *a, t_deque *b);
int		atoi_safe(const char *str);

#endif
