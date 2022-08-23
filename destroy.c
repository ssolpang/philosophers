/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:38:25 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/23 15:53:01 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	destroy_mutex_4_forks(int i, t_param *param)
{
	int	start;

	start = 0;
	while (start < i)
	{
		pthread_mutex_destroy(&param->forks[start]);
		++start;
	}
	free(param->forks);
}

void	destroy_mutex_4_others(int i, t_param *param)
{
	if (i > 0)
	{
		pthread_mutex_destroy(&param->print_lock);
		if (i > 1)
		{
			pthread_mutex_destroy(&param->is_dining_lock);
			if (i > 2)
				pthread_mutex_destroy(&param->get_time_lock);
		}
	}
}