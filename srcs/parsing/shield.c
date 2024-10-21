/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:46:21 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 22:42:18 by lsaumon          ###   ########.fr       */
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

void	ft_usleep(long ms)
{
	usleep(ms * 1000);
}

long	get_time(void)
{
	struct	timeval current_time;
	long	time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = (current_time.tv_sec * 1000)
					+ (current_time.tv_usec / 1000);
	return (time_in_ms);	
}
