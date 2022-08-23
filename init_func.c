/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:17:43 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/23 21:24:07 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static int	init_mutex_routine(pthread_mutex_t *lock, t_param *param, int i)
{
	if (pthread_mutex_init(lock, NULL))
	{
		destroy_mutex_4_others(i, param);
		return (FAIL);
	}
	return (SUCCESS);
}

static int	init_each_mutex(t_param *param)
{
	if (!init_mutex_routine(&param->print_lock, param, 0))
		return (FAIL);
	if (!init_mutex_routine(&param->is_dining_lock, param, 1))
		return (FAIL);
	if (!init_mutex_routine(&param->get_time_lock, param, 2))
		return (FAIL);
	if (!init_mutex_routine(&param->starving_time_lock, param, 3))
		return (FAIL);
	if (!init_mutex_routine(&param->eat_count_lock, param, 4))
		return (FAIL);
	return (SUCCESS);
}

int	init_forks_mutex(t_param *param, t_rule *rule)
{
	int	i;

	param->forks = malloc(sizeof(pthread_mutex_t) * rule->num_of_philo);
	if (!param->forks)
	{
		destroy_mutex_4_others(5, param);
		return (FAIL);
	}
	i = 0;
	while (i < rule->num_of_philo)
	{
		if (pthread_mutex_init(&param->forks[i], NULL))
		{
			destroy_mutex_4_others(5, param);
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
		destroy_mutex_4_others(5, param);
		destroy_mutex_4_forks(param->rule->num_of_philo, param);
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
		destroy_mutex_4_others(5, param);
		destroy_mutex_4_forks(rule->num_of_philo, param);
		return (FAIL);
	}
	if (!init_philo(param))
		return (FAIL);
	return (SUCCESS);
}
