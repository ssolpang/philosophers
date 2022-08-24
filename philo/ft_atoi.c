/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:16:53 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/08 15:16:55 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	if (str[i] == '+')
		++i;
	result = 0;
	while (ft_is_digit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (result < -2147483648 || result > 2147483647)
		return (FAIL);
	return ((int)(result));
}
