/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:18:41 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/24 15:46:19 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	spending_time(t_param *param, long long time_to_spend)
{
	long long	target_time;

	target_time = get_time(param) + time_to_spend;
	while (get_time(param) < target_time)
		usleep(100);
}

void	philo_eat(t_rule *rule, t_philo *philo, int tid)
{
	pthread_mutex_lock(&philo->param->is_dining_lock);
	if (rule->is_dining == FALSE)
	{
		pthread_mutex_unlock(&philo->param->is_dining_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->param->is_dining_lock);
	print_terminal(philo->param, tid + 1, "is eating");
	pthread_mutex_lock(&philo->param->starving_time_lock);
	philo->start_starving_time = get_time(philo->param);
	pthread_mutex_unlock(&philo->param->starving_time_lock);
	spending_time(philo->param, rule->time_to_eat);
	pthread_mutex_lock(&philo->param->eat_count_lock);
	++(philo->eat_count);
	pthread_mutex_unlock(&philo->param->eat_count_lock);
}

void	philo_sleep(t_rule *rule, t_philo *philo, int tid)
{
	pthread_mutex_lock(&philo->param->is_dining_lock);
	if (rule->is_dining == FALSE)
	{
		pthread_mutex_unlock(&philo->param->is_dining_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->param->is_dining_lock);
	print_terminal(philo->param, tid + 1, "is sleeping");
	spending_time(philo->param, rule->time_to_sleep);
}

void	philo_think(t_rule *rule, t_philo *philo, int tid)
{
	pthread_mutex_lock(&philo->param->is_dining_lock);
	if (rule->is_dining == FALSE)
	{
		pthread_mutex_unlock(&philo->param->is_dining_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->param->is_dining_lock);
	print_terminal(philo->param, tid + 1, "is thinking");
	usleep(50);
}
