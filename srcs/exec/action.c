/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:59:05 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/25 09:28:14 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philosopher_think(t_philo *philosopher)
{
	safe_print(philosopher, "is thinking");
}

void	philosopher_take_forks(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	safe_print(philosopher, "has taken a fork");
	pthread_mutex_lock(philosopher->right_fork);
	safe_print(philosopher, "has taken a fork");
}

void	philosopher_eat(t_philo *philosopher)
{
	philosopher_take_forks(philosopher);
	safe_print(philosopher, "is eating");
	pthread_mutex_lock(&philosopher->meal_time_mutex);
	philosopher->last_meal_time = get_time(philosopher->params);
	pthread_mutex_unlock(&philosopher->meal_time_mutex);
	ft_usleep(philosopher->params->time_to_eat, philosopher);
	pthread_mutex_lock(&philosopher->params->finish_mutex);
	philosopher->meals_eaten++;
	pthread_mutex_unlock(&philosopher->params->finish_mutex);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	philosopher_sleep(t_philo *philosopher)
{
	safe_print(philosopher, "is sleeping");
	ft_usleep(philosopher->params->time_to_sleep, philosopher);
}

void	one_philo_one_fork(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	safe_print(philosopher, "has taken a fork");
	ft_usleep(philosopher->params->time_to_die, philosopher);
	pthread_mutex_lock(&philosopher->params->sim_run_mutex);
	if (philosopher->params->sim_run)
	{
		philosopher->params->sim_run = 0;
		pthread_mutex_lock(&philosopher->params->print_mutex);
		printf("[%ld ms] Philo %d has died.\n",
			get_time(philosopher->params), philosopher->id);
		pthread_mutex_unlock(&philosopher->params->print_mutex);
	}
	pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
	pthread_mutex_unlock(philosopher->left_fork);
}
