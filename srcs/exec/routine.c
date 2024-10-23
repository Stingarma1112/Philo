/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 06:58:51 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/23 07:04:09 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo		*philosopher;

	philosopher = (t_philo *)arg;
	while (1)
	{
		if (check_simulation_status(philosopher)
			|| check_meals(philosopher) || check_death(philosopher))
			break ;
		philosopher_think(philosopher);
		if (check_simulation_status(philosopher)
			|| check_death(philosopher))
			break ;
		philosopher_eat(philosopher);
		if (check_simulation_status(philosopher)
			|| check_death(philosopher))
			break ;
		philosopher_sleep(philosopher);
		if (check_simulation_status(philosopher)
			|| check_death(philosopher))
			break ;
	}
	return (NULL);
}

int	check_simulation_status(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->params->sim_run_mutex);
	if (!philosopher->params->sim_run)
	{
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
	return (0);
}

int	check_meals(t_philo *philosopher)
{
	if (philosopher->params->meals_required != -1
		&& philosopher->meals_eaten >= philosopher->params->meals_required)
		return (1);
	return (0);
}
