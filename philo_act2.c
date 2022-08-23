/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:18:41 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/23 16:43:08 by jkwak            ###   ########.fr       */
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
	if (rule->is_dining == FALSE)
		return ;
	print_terminal(philo->param, tid + 1, "is eating");
	philo->start_starving_time = get_time(philo->param);
	spending_time(philo->param, rule->time_to_eat);
	++(philo->eat_count);
}

void	philo_sleep(t_rule *rule, t_philo *philo, int tid)
{
	if (rule->is_dining == FALSE)
		return ;
	print_terminal(philo->param, tid + 1, "is sleeping");
	spending_time(philo->param, rule->time_to_sleep);
}

void	philo_think(t_rule *rule, t_philo *philo, int tid)
{
	if (rule->is_dining == FALSE)
		return ;
	print_terminal(philo->param, tid + 1, "is thinking");
	usleep(50);
}
