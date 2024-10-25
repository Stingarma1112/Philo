/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:22:40 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/25 23:00:58 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	signe;

	i = 0;
	n = 0;
	signe = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] - 48;
		i++;
	}
	return (n * signe);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	create_philosophers(t_philo *philosophers, t_params *params)
{
	int	i;

	i = 0;
	while (i < params->nbr_of_philo)
	{
		if (pthread_create(&philosophers[i].thread, NULL,
				philosopher_routine, &philosophers[i]) != 0)
		{
			printf("Error: Failed to create thread for philosopher %d\n",
				philosophers[i].id);
			free_resources(philosophers, params, params->nbr_of_philo);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	join_philosophers(t_philo *philosophers, t_params *params)
{
	int	i;

	i = 0;
	while (i < params->nbr_of_philo)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		*philosophers;
	pthread_t	monitor_thread;

	if (parsing(&philosophers, &params, argc, argv))
		return (1);
	params.start_time = get_current_time_in_ms();
	if (create_philosophers(philosophers, &params))
		return (1);
	if (pthread_create(&monitor_thread, NULL, monitor_routine,
			(void *)philosophers) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		free_resources(philosophers, &params, params.nbr_of_philo);
		return (1);
	}
	pthread_join(monitor_thread, NULL);
	join_philosophers(philosophers, &params);
	free_resources(philosophers, &params, params.nbr_of_philo);
	return (0);
}
