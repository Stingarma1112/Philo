/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:54:31 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/24 19:11:28 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	parsing(t_philo	**philo, t_params *params, int argc, char **argv)
{
	if (!init_params(params, argc, argv))
		return (1);
	if (!init_fork_mutexes(params) || !init_other_mutexes(params))
	{
		free(params->forks);
		return (1);
	}
	*philo = malloc(sizeof(t_philo) * params->nbr_of_philo);
	if (!(*philo))
	{
		printf("Error: Memory allocation failed\n");
		free(params->forks);
		return (1);
	}
	if (!init_philosophers(*philo, params))
	{
		free(*philo);
		free(params->forks);
		return (1);
	}
	return (0);
}

void	safe_print(t_philo *philosopher, char *message)
{
	pthread_mutex_lock(&philosopher->params->sim_run_mutex);
	if (philosopher->params->sim_run)
	{
		pthread_mutex_lock(&philosopher->params->print_mutex);
		printf("[%ld ms]Philo %d %s\n",
			get_time(philosopher->params), philosopher->id, message);
		pthread_mutex_unlock(&philosopher->params->print_mutex);
	}
	pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
}
