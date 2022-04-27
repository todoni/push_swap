/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:52:36 by sohan             #+#    #+#             */
/*   Updated: 2021/05/24 20:14:01 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int	is_exceed(int a, int b)
{
	int	a_old;

	a_old = a;
	a *= 10;
	if ((a / 10 != a_old) || \
		(a > 0 && b > INT_MAX - a) || \
		(a < 0 && b < INT_MIN - a))
		return (1);
	return (0);
}

int	atoi_safe(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	sign += -2 * (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		terminate();
	while (ft_isdigit(*str))
	{
		if (is_exceed(result, (*str - '0') * sign))
			terminate();
		result *= 10;
		result += (*str - 48) * sign;
		str++;
	}
	return (result);
}
