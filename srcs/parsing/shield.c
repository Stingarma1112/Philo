/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:46:21 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/22 17:08:35 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_ressources(t_philo *philosophers, t_params *params, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&params->forks[i]);
		i++;
	}
	if (count == params->nbr_of_philo)
		pthread_mutex_destroy(&params->print_mutex);
	free(philosophers);
	free(params->forks);
}

void	ft_usleep(long time_in_ms, t_params *params)
{
    long start_time;
	
	start_time = get_time(params);
    while ((get_time(params) - start_time) < time_in_ms)
    {
        pthread_mutex_lock(&params->sim_run_mutex);
        if (!params->sim_run)
        {
            pthread_mutex_unlock(&params->sim_run_mutex);
            break;
        }
        pthread_mutex_unlock(&params->sim_run_mutex);

        usleep(1000);
    }
}

long	get_time(t_params *params)
{
	struct	timeval current_time;
	long	time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = (current_time.tv_sec * 1000)
					+ (current_time.tv_usec / 1000);
	return (time_in_ms - params->start_time);	
}
