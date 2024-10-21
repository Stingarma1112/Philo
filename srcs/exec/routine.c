/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:59:05 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 22:43:27 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philosopher_think(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->params->print_mutex);
	printf("Philo %d is thinking...\n", philosopher->id);
	pthread_mutex_unlock(&philosopher->params->print_mutex);
}

void	philosopher_eat(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	pthread_mutex_lock(philosopher->right_fork);
	pthread_mutex_lock(&philosopher->params->print_mutex);
	printf("Philo %d is eating...\n", philosopher->id);
	pthread_mutex_unlock(&philosopher->params->print_mutex);
	philosopher->last_meal_time = get_time();
	ft_usleep(philosopher->params->time_to_eat);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	philosopher_sleep(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->params->print_mutex);
	printf("Philo %d is sleeping...\n", philosopher->id);
	pthread_mutex_unlock(&philosopher->params->print_mutex);
	ft_usleep(philosopher->params->time_to_sleep);
}

void	*philosopher_routine(void *arg)
{
	t_philo		*philosopher = (t_philo *)arg;
	t_params	*params = philosopher->params;

	while (params->sim_run)
	{
		philosopher_think(philosopher);
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
	}
	return (NULL);
}