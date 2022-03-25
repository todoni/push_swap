/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:18:10 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 21:18:12 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include <stdlib.h>

typedef struct s_heap
{
	int		*array;
	int		size;
}	t_heap;

void	heap_initialize(t_heap *heap, int size);
void	heap_insert(t_heap *heap, int item);
int		heap_delete(t_heap *heap);

#endif
