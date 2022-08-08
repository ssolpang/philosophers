/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:16:04 by jkwak             #+#    #+#             */
/*   Updated: 2022/08/08 15:16:06 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_must_eat(int argc, char **argv, t_rule *rule)
{
	if (argc == 6)
	{
		rule->count_of_must_eat = ft_atoi(argv[5]);
		rule->if_count_of_must_eat = TRUE;
	}
	else
	{
		rule->count_of_must_eat = INFINITY;
		rule->if_count_of_must_eat = FALSE;
	}
}

static int	check_valid_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+')
			++j;
		while (argv[i][j])
		{
			if (!ft_is_digit(argv[i][j]))
				return (FAIL);
			++j;
		}
		++i;
	}
	return (SUCCESS);
}

static int	check_valid_rule(t_rule *rule)
{
	if (rule->num_of_philo <= 0 || rule->time_to_die <= 0 \
		|| rule->time_to_eat <= 0 || rule->time_to_sleep <= 0)
		return (FAIL);
	if (rule->if_count_of_must_eat == TRUE && rule->count_of_must_eat == 0)
		return (FAIL);
	return (SUCCESS);
}

int	parsing(int argc, char **argv, t_rule *rule)
{
	if (argc != 5 && argc != 6)
		return (FAIL);
	if (!check_valid_argv(argc, argv))
		return (FAIL);
	rule->num_of_philo = ft_atoi(argv[1]);
	rule->time_to_die = ft_atoi(argv[2]);
	rule->time_to_eat = ft_atoi(argv[3]);
	rule->time_to_sleep = ft_atoi(argv[4]);
	rule->is_dining = TRUE;
	get_must_eat(argc, argv, rule);
	if (!check_valid_rule(rule))
		return (FAIL);
	return (SUCCESS);
}
