/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:35:18 by sohan             #+#    #+#             */
/*   Updated: 2022/04/27 13:35:21 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	terminate(void)
{
	if (write(2, "Error\n", 6) == -1)
		exit(3);
	exit(1);
}

void	print_instruction(const char *instruction)
{
	if (write(1, instruction, ft_strlen(instruction)) == -1)
		terminate();
}
