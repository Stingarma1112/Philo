/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:20:10 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/24 17:03:45 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	validate_params(t_params *params)
{
	if (params->nbr_of_philo <= 0 || params->time_to_die <= 0
		|| params->time_to_eat <= 0 || params->time_to_sleep <= 0
		|| (params->meals_required != -1 && params->meals_required <= 0))
	{
		printf("Error: Invalid arg value.\n");
		return (0);
	}
	return (1);
}

int	init_params(t_params *params, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Usage : %s 'philo' 'time_to_d' 'time_to_e' ", argv[0]);
		printf("'time_to_sleep' '[meals_required]'\n");
		return (0);
	}
	params->nbr_of_philo = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		params->meals_required = ft_atoi(argv[5]);
	else
		params->meals_required = -1;
	if (!validate_params(params))
		return (0);
	params->forks = malloc(sizeof(pthread_mutex_t) * params->nbr_of_philo);
	if (!params->forks)
	{
		printf("Error: Memory allocation failed.\n");
		return (0);
	}
	params->sim_run = 1;
	params->philosophers_finished = 0;
	return (1);
}

int	init_fork_mutexes(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->nbr_of_philo)
	{
		if (pthread_mutex_init(&params->forks[i], NULL) != 0)
		{
			printf("Error: Failed to init mutex for fork %d\n", i);
			free_resources(NULL, params, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_other_mutexes(t_params *params)
{
	if (pthread_mutex_init(&params->print_mutex, NULL) != 0)
	{
		printf("Error: Failed to init print mutex\n");
		free_resources(NULL, params, params->nbr_of_philo);
		return (0);
	}
	if (pthread_mutex_init(&params->sim_run_mutex, NULL) != 0)
	{
		printf("Error: Failed to init sim_run mutex\n");
		free_resources(NULL, params, params->nbr_of_philo);
		return (0);
	}
	if (pthread_mutex_init(&params->finish_mutex, NULL) != 0)
	{
		printf("Error: Failed to init finish mutex\n");
		free_resources(NULL, params, params->nbr_of_philo);
		return (0);
	}
	return (1);
}

int	init_philosophers(t_philo *philosophers, t_params *params)
{
	int	i;

	i = 0;
	while (i < params->nbr_of_philo)
	{
		philosophers[i].id = i + 1;
		philosophers[i].left_fork = &params->forks[i];
		philosophers[i].right_fork = &params->forks[(i + 1)
			% params->nbr_of_philo];
		philosophers[i].last_meal_time = get_time(params);
		philosophers[i].meals_eaten = 0;
		philosophers[i].params = params;
		if (pthread_mutex_init(&philosophers[i].meal_time_mutex, NULL) != 0)
		{
			printf("Error: Failed to init meal_time mutex for philosopher %d\n",
				philosophers[i].id);
			return (0);
		}
		i++;
	}
	return (1);
}
