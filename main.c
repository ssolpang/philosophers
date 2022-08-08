/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:15:50 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/08 15:15:53 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_rule	rule;

	if (!parsing(argc, argv, &rule))
	{
		printf("FAIL\n");
		return (0);
	}
	philo_run(&rule);
	return (0);
}
