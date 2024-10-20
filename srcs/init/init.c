/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:20:10 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 01:45:07 by lsaumon          ###   ########.fr       */
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
		printf("Usage : %s 'nbr_of_philo' 'time_to_die' 'time_to_eat' ", argv[0]);
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
	return (1);
}
