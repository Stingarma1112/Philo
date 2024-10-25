/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:46:21 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/24 19:11:36 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_resources(t_philo *philosophers, t_params *params, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&params->forks[i]);
		pthread_mutex_destroy(&philosophers[i].meal_time_mutex);
		i++;
	}
	if (count == params->nbr_of_philo)
	{
		pthread_mutex_destroy(&params->print_mutex);
		pthread_mutex_destroy(&params->sim_run_mutex);
		pthread_mutex_destroy(&params->finish_mutex);
	}
	free(philosophers);
	free(params->forks);
}

void	ft_usleep(long time_in_ms, t_philo *philosopher)
{
	long	start_time;

	start_time = get_current_time_in_ms();
	while ((get_current_time_in_ms() - start_time) < time_in_ms)
	{
		pthread_mutex_lock(&philosopher->params->sim_run_mutex);
		if (!philosopher->params->sim_run)
		{
			pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
			break ;
		}
		pthread_mutex_unlock(&philosopher->params->sim_run_mutex);
		usleep(1000);
	}
}

long	get_current_time_in_ms(void)
{
	struct timeval	current_time;
	long			time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = (current_time.tv_sec * 1000)
		+ (current_time.tv_usec / 1000);
	return (time_in_ms);
}

long	get_time(t_params *params)
{
	return (get_current_time_in_ms() - params->start_time);
}
