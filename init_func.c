/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:17:43 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/22 19:44:57 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static int	init_each_mutex(t_param *param)
{
	if (pthread_mutex_init(&param->print_lock, NULL))
	{
		destroy_mutex_4_others(1, param);
		return (FAIL);
	}
	if (pthread_mutex_init(&param->is_dining_lock, NULL))
	{
		destroy_mutex_4_others(2, param);
		return (FAIL);
	}
	if (pthread_mutex_init(&param->get_time_lock, NULL))
	{
		destroy_mutex_4_others(3, param);
		return (FAIL);
	}
	return (SUCCESS);
}

int	init_forks_mutex(t_param *param, t_rule *rule)
{
	int	i;

	param->forks = malloc(sizeof(pthread_mutex_t) * rule->num_of_philo);
	if (!param->forks)
	{
		destroy_mutex_4_others(3, param);
		return (FAIL);
	}
	i = 0;
	while (i < rule->num_of_philo)
	{
		if (pthread_mutex_init(&param->forks[i], NULL))
		{
			destroy_mutex_4_others(3, param);
			destroy_mutex_4_forks(i, param);
			return (FAIL);
		}
		++i;
	}
	return (SUCCESS);
}

static int	init_philo(t_param *param)
{
	int	i;

	param->philo = malloc(sizeof(t_philo) * param->rule->num_of_philo);
	if (!param->philo)
	{
		destroy_mutex_4_others(3, param);
		destroy_mutex_4_forks(i, param);
		free(param->tids);
		return (FAIL);
	}
	i = 0;
	while (i < param->rule->num_of_philo)
	{
		param->philo[i].param = param;
		param->philo[i].eat_count = 0;
		param->philo[i].start_starving_time = get_time(param);
		param->philo[i].left_fork = &param->forks[i];
		param->philo[i].right_fork = &param->forks[(i + 1) \
			% param->rule->num_of_philo];
		++i;
	}
	return (SUCCESS);
}


int	init_param(t_param *param, t_rule *rule)
{
	param->rule = rule;
	if (!init_each_mutex(param))
		return (FAIL);
	if (!init_forks_mutex(param, rule))
		return (FAIL);
	param->tids = malloc(sizeof(pthread_t) * rule->num_of_philo);
	if (!param->tids)
	{
		destroy_mutex_4_others(3, param);
		destroy_mutex_4_forks(i, param);
		return (FAIL);
	}
	if (!init_philo(param))
		return (FAIL);
	return (SUCCESS);
}
