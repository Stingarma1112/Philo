/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 06:58:51 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/24 18:26:20 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// void	*philosopher_routine(void *arg)
// {
// 	t_philo		*philosopher;

// 	philosopher = (t_philo *)arg;
// 	while (1)
// 	{
// 		if (check_simulation_status(philosopher)
// 			|| check_meals(philosopher) || check_death(philosopher))
// 			break ;
// 		philosopher_think(philosopher);
// 		if (check_simulation_status(philosopher)
// 			|| check_death(philosopher))
// 			break ;
// 		philosopher_eat(philosopher);
// 		if (check_simulation_status(philosopher)
// 			|| check_death(philosopher))
// 			break ;
// 		philosopher_sleep(philosopher);
// 		if (check_simulation_status(philosopher)
// 			|| check_death(philosopher))
// 			break ;
// 	}
// 	return (NULL);
// }

void	*philosopher_routine(void *arg)
{
	t_philo		*philosopher;

	philosopher = (t_philo *)arg;
	if (philosopher->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philosopher->params->sim_run_mutex);
		if (!philosopher->params->sim_run)
		{
			pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
			break ;
		}
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
	return (NULL);
}

// int	check_simulation_status(t_philo *philosopher)
// {
// 	pthread_mutex_lock(&philosopher->params->sim_run_mutex);
// 	if (!philosopher->params->sim_run)
// 	{
// 		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
// 	return (0);
// }

// int	check_meals(t_philo *philosopher)
// {
// 	if (philosopher->params->meals_required != -1
// 		&& philosopher->meals_eaten >= philosopher->params->meals_required)
// 		return (1);
// 	return (0);
// }

void	*monitor_routine(void *arg)
{
	t_philo		*philosophers;
	t_params	*params;
	int			i;
	int			all_finished;

	philosophers = (t_philo *)arg;
	params = philosophers[0].params;
	while (1)
	{
		i = 0;
		all_finished = 1;
		while (i < params->nbr_of_philo)
		{
			pthread_mutex_lock(&philosophers[i].meal_time_mutex);
			if ((get_time(params) - philosophers[i].last_meal_time)
				> params->time_to_die)
			{
				pthread_mutex_lock(&params->sim_run_mutex);
				if (params->sim_run)
				{
					params->sim_run = 0;
					pthread_mutex_lock(&params->print_mutex);
					printf("[%ld ms] Philo %d has died.\n",
						get_time(params), philosophers[i].id);
					pthread_mutex_unlock(&params->print_mutex);
				}
				pthread_mutex_unlock(&params->sim_run_mutex);
				pthread_mutex_unlock(&philosophers[i].meal_time_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philosophers[i].meal_time_mutex);
			pthread_mutex_lock(&params->finish_mutex);
			if (params->meals_required == -1
				|| philosophers[i].meals_eaten < params->meals_required)
				all_finished = 0;
			pthread_mutex_unlock(&params->finish_mutex);
			i++;
		}
		if (all_finished)
		{
			pthread_mutex_lock(&params->sim_run_mutex);
			params->sim_run = 0;
			pthread_mutex_unlock(&params->sim_run_mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
