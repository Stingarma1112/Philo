/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:59:05 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/23 07:12:58 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philosopher_think(t_philo *philosopher)
{
	safe_print(philosopher, "is thinking");
	ft_usleep(philosopher->params->time_to_sleep, philosopher);
}

void	philosopher_take_forks(t_philo *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		pthread_mutex_lock(philosopher->left_fork);
		safe_print(philosopher, "has taken a fork");
		pthread_mutex_lock(philosopher->right_fork);
		safe_print(philosopher, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philosopher->right_fork);
		safe_print(philosopher, "has taken a fork");
		pthread_mutex_lock(philosopher->left_fork);
		safe_print(philosopher, "has taken a fork");
	}
}

void	check_meals_eaten(t_philo *philosopher)
{
	if (philosopher->params->meals_required != -1
		&& philosopher->meals_eaten >= philosopher->params->meals_required)
	{
		pthread_mutex_lock(&philosopher->params->finish_mutex);
		philosopher->params->philosophers_finished++;
		if (philosopher->params->philosophers_finished
			>= philosopher->params->nbr_of_philo)
		{
			pthread_mutex_lock(&philosopher->params->sim_run_mutex);
			philosopher->params->sim_run = 0;
			pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		}
		pthread_mutex_unlock(&philosopher->params->finish_mutex);
		pthread_mutex_unlock(philosopher->right_fork);
		pthread_mutex_unlock(philosopher->left_fork);
		return ;
	}
}

void	philosopher_eat(t_philo *philosopher)
{
	philosopher_take_forks(philosopher);
	pthread_mutex_lock(&philosopher->params->sim_run_mutex);
	if (philosopher->params->sim_run)
	{
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		safe_print(philosopher, "is eating");
		philosopher->last_meal_time = get_time(philosopher->params);
		ft_usleep(philosopher->params->time_to_eat, philosopher);
		philosopher->meals_eaten++;
		check_meals_eaten(philosopher);
	}
	else
	{
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
	}
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
	if (check_death(philosopher))
		return ;
}

void	philosopher_sleep(t_philo *philosopher)
{
	safe_print(philosopher, "is sleeping");
	ft_usleep(philosopher->params->time_to_sleep, philosopher);
	if (check_death(philosopher))
		return ;
}
