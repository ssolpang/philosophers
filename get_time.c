/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:15:30 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/08 15:15:34 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long long	get_time(t_param *param)
{
	struct timeval	time;
	long long		ms;

	pthread_mutex_lock(&param->get_time_lock);
	gettimeofday(&time, NULL);
	pthread_mutex_unlock(&param->get_time_lock);
	ms = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	return (ms);
}
