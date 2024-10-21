/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:54:31 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/22 01:11:13 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	parsing(t_philo	**philosophers, t_params *params, int argc, char **argv)
{
	if (!init_params(params, argc, argv))
		return (1);
	if (!init_mutexes(params))
	{
		free(params->forks);
		return (1);
	}
	*philosophers = malloc(sizeof(t_philo) * params->nbr_of_philo);
	if (!(*philosophers))
	{
		printf("Error: Memory allocation failed\n");
		free(params->forks);
		return (1);
	}
	if (!init_philosophers(*philosophers, params))
	{
		free(*philosophers);
		free(params->forks);
		return (1);
	}
	return (0);
}

int	check_death(t_philo *philosopher)
{
	long	current_time;

	current_time = get_time();
	if ((current_time - philosopher->last_meal_time)
		> philosopher->params->time_to_die)
	{
		pthread_mutex_lock(&philosopher->params->print_mutex);
		printf("Philo %d has died at %ld ms.\n", philosopher->id, current_time);
		pthread_mutex_unlock(&philosopher->params->print_mutex);
		pthread_mutex_lock(&philosopher->params->sim_run_mutex);
		philosopher->params->sim_run = 0;
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		return (1);
	}
	return (0);
}
