/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:22:40 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/24 16:51:02 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_params	params;
	t_philo		*philosophers;
	pthread_t	monitor_thread;
	int			i;

	if (parsing(&philosophers, &params, argc, argv))
		return (1);
	params.start_time = get_current_time_in_ms();
	i = 0;
	while (i < params.nbr_of_philo)
	{
		philosophers[i].last_meal_time = params.start_time;
		i++;
	}
	i = 0;
	while (i < params.nbr_of_philo)
	{
		if (pthread_create(&philosophers[i].thread, NULL,
				philosopher_routine, &philosophers[i]) != 0)
		{
			printf("Error: Failed to create thread for philosopher %d\n",
				philosophers[i].id);
			free_resources(philosophers, &params, params.nbr_of_philo);
			return (1);
		}
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor_routine, philosophers) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		free_resources(philosophers, &params, params.nbr_of_philo);
		return (1);
	}
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < params.nbr_of_philo)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
	free_resources(philosophers, &params, params.nbr_of_philo);
	return (0);
}
